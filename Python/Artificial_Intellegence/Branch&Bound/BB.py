'''
Created on Mar 26, 2011
@author: assem,chelli


Demo: 

> un exemple de base
> PVC environnement et implementation
> FIFO avec/sans priorite
> avec "fonction d'estimation" et/ou "fonction du cout"
> graphe oriente
> la contrainte : une seule visite (non implemente)
> autres exemples



'''

# MIN,Max Value for BB limits for a general problem
MIN, MAX = 0, 9999999

import math
import os
import sys

import pygame


class Problem:
    def __init__(self, sample=None):
        self.initial = None
        pass

    def successors(self, coloring):
        return []

    def h(self, config):  # rest to colorize
        return 0

    def g(self, config):  # number of colors used
        return 0

    def f(self, config):
        return self.g(config) + self.h(config)

    def objective(self, config):
        return (config.values().count(0) == 0)

    pass

    def Max(self):
        return MAX;

    def Min(self):
        return MIN;


class PVC(Problem):
    def __init__(self, sample=None):
        if sample:
            g = sample
        else:
            g = self.Sample_Basic()

        self.initial = g.chemin
        self.towns = g.towns
        self.links = g.links
        self.distances = g.distances
        self.positions = g.positions

    window = None  # graphical window

    class Sample_Basic:
        towns = [1, 2, 3, 4, 5]
        links = {1: [2, 5], 2: [1, 3, 5, 4], 3: [2, 4], 4: [3, 5, 2], 5: [2, 4, 1]}
        distances = {(1, None): 0, (1, 3): 130, (1, 4): 290, (1, 2): 300, (1, 5): 200, (2, 1): 300, (2, 3): 400,
                     (2, 4): 200, (2, 5): 250, (3, 2): 400, (3, 4): 100, (3, 1): 130, (4, 1): 290, (4, 3): 100,
                     (4, 5): 200, (4, 2): 200, (5, 4): 200, (5, 1): 200, (5, 2): 250}
        positions = {1: (0, 4), 2: (4, 0), 3: (2, -4), 4: (-2, -4), 5: (-4, 0)}
        chemin = [(1, None)]

    def successors(self, chemin):
        succ = []
        chemin = list(chemin)
        current = chemin[-1][1]
        if current is None:
            current = chemin[-1][0]
            chemin.pop()
        for next in self.links[current]:
            if next not in self.visited(chemin):
                new_chemin = list(chemin)
                new_chemin.append((current, next))
                succ.append(new_chemin)
        return succ

    def visited(self, chemin):
        visited_towns = []
        for d in chemin[1:]:
            visited_towns.append(d[0])
            visited_towns.append(d[1])
        return list(set(visited_towns))

    def h(self, chemin):
        return 0  # len(set(self.towns)-set(self.visited(chemin)))*max(self.distances.values())

    def g(self, chemin):
        distance = 0
        for d in chemin:
            distance += self.distances[d]
        return distance

    def f(self, chemin):
        return self.h(chemin) + self.g(chemin)  # h=0 => BEST MOVE #g=0 => FIRSt admissible move

    def objective(self, chemin):
        return (set(self.towns) == set(self.visited(chemin))) and chemin[0][0] == chemin[-1][1]  # hamiltoian
        # return (set(self.towns)==set(self.visited(chemin)))

    def init_game(self):
        pygame.init()
        WX = WY = 600
        self.window = pygame.display.set_mode((WX, WY))
        pygame.display.set_caption("Branch & Bound - PVC")
        if pygame.font:
            self.font = pygame.font.Font(None, 30)

    def Vcoords(self, Rcoords):
        return (Rcoords[0] * 45 + 300, 600 - (Rcoords[1] * 45 + 300))

    def draw(self, chemin):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0
        #####
        text = self.font.render(str(self.g(chemin)), 2, (255, 0, 0))
        x, y = 50, 50
        textpos = text.get_rect(centerx=x, centery=y)
        self.window.blit(text, textpos)

        for (source, destinations) in self.links.items():
            source_position = self.Vcoords(self.positions[source])
            for destination in destinations:
                if ((source, destination) in chemin) or ((destination, source) in chemin):
                    color = (0, 200, 0)
                else:
                    color = (255, 255, 255)
                destination_position = self.Vcoords(self.positions[destination])
                pygame.draw.line(self.window, color, source_position, destination_position, 5)
                text = self.font.render(str(self.distances[(source, destination)]), 2, (255, 0, 0))
                x, y = (destination_position[0] + source_position[0]) / 2, (
                destination_position[1] + source_position[1]) / 2
                textpos = text.get_rect(centerx=x, centery=y)
                self.window.blit(text, textpos)

        for p in self.towns:
            if not chemin:
                color = (200, 200, 200)
            elif p == chemin[0][0] == chemin[-1][1]:
                color = (255, 0, 255)
            elif p == chemin[0][0]:
                color = (0, 0, 255)
            elif p == chemin[-1][1]:
                color = (255, 0, 0)
            elif p in self.visited(chemin):
                color = (0, 200, 0)
            else:
                color = (255, 255, 255)

            pygame.draw.circle(self.window, color, self.Vcoords(self.positions[p]), 20, 20)
            text = self.font.render(str(p), 2, (0, 0, 0))
            x, y = self.Vcoords(self.positions[p])
            textpos = text.get_rect(centerx=x, centery=y)
            self.window.blit(text, textpos)

        # draw it to the screen
        pygame.display.flip()

    def wait_game(self):
        stop = False
        while not stop:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pass
                    sys.exit(0)
                elif event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN:
                    stop = True;
                    break;
                else:
                    # print event
                    pass


class Labyrinth(Problem):
    def __init__(self, sample=None):
        if sample:
            g = sample
        else:
            g = Sample_Basic()

        self.width = g.width
        self.hight = g.hight
        self.blocks = g.blocks
        self.goal = g.goal
        self.initial = g.player

    window = None

    class Sample_Basic:
        width = 10
        hight = 5
        blocks = [(0, 0), (1, 2), (2, 1), (2, 2), (2, 3), (3, 3), (4, 1), (4, 3), (5, 1), (5, 2), (5, 3), (7, 0),
                  (7, 2), (7, 3), (8, 0), (9, 2)]
        player = (4, 2)
        goal = (4, 4)

    class Sample_1(Sample_Basic):
        width = 10
        hight = 5
        blocks = [(0, 0), (1, 2), (2, 1), (2, 2), (2, 3), (3, 3), (3, 4), (4, 1), (4, 3), (5, 1), (5, 2), (5, 3),
                  (7, 0), (7, 2), (7, 3), (8, 0), (9, 2)]
        player = (4, 2)
        goal = (4, 4)

    def successors(self, player):
        succ = []
        # test borns
        player_ = {"up": (player[0], player[1] - 1) if player[1] else None,
                   "down": (player[0], player[1] + 1) if self.hight - player[1] - 1 else None,
                   "right": (player[0] + 1, player[1]) if self.width - player[0] - 1 else None,
                   "left": (player[0] - 1, player[1]) if player[0] else None}
        # test_blocks
        for p in player_.values():
            if p and p not in self.blocks:
                succ.append(p)

        return succ

    def g(self, player):
        return math.sqrt(math.pow(2, (player[0] - self.initial[0])) + math.pow(2, (player[1] - self.initial[1])))

    def h(self, player):
        return math.sqrt(math.pow(2, (player[0] - self.goal[0])) + math.pow(2, (player[1] - self.goal[1])))

    def f(self, config):
        return 0 * self.g(config) + self.h(config)

    def objective(self, player):
        return player == self.goal

    def init_game(self):
        pygame.init()
        WX = WY = 600
        self.window = pygame.display.set_mode((WX, WY))
        if pygame.font:
            self.font = pygame.font.Font(None, 30)

    def Vcoords(self, Rcoords):
        return (Rcoords[0] * 45 + 100, Rcoords[1] * 45 + 100)

    def draw(self, trace):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0

        for i in range(self.width + 1):
            if i != self.width:
                text = self.font.render(str(i), 2, (255, 255, 255))
                x, y = self.Vcoords((i, -1))
                textpos = text.get_rect(centerx=x + 25, centery=y + 25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255, 255, 255), self.Vcoords((i, 0)), self.Vcoords((i, self.hight)))

        for j in range(self.hight + 1):
            if j != self.hight:
                text = self.font.render(str(j), 2, (255, 255, 255))
                x, y = self.Vcoords((-1, j))
                textpos = text.get_rect(centerx=x + 25, centery=y + 25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255, 255, 255), self.Vcoords((0, j)), self.Vcoords((self.width, j)))

        for b in self.blocks:
            start = self.Vcoords(b)

            pygame.draw.rect(self.window, (255, 0, 0), (start[0] + 10, start[1] + 10, 25, 25), 10)

        # initial
        color = (0, 255, 0)
        text = self.font.render("#", 2, color)
        x, y = self.Vcoords(self.initial)
        textpos = text.get_rect(centerx=x + 25, centery=y + 25)
        self.window.blit(text, textpos)

        # goal
        color = (0, 255, 0)
        text = self.font.render("$", 2, color)
        x, y = self.Vcoords(self.goal)
        textpos = text.get_rect(centerx=x + 20, centery=y + 20)
        self.window.blit(text, textpos)

        # last
        text = self.font.render("+", 2, (255, 255, 0))
        x, y = self.Vcoords(trace)
        textpos = text.get_rect(centerx=x + 20, centery=y + 20)
        self.window.blit(text, textpos)

        # draw it to the screen
        pygame.display.flip()

    def draw_trace(self, trace):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0

        for i in range(self.width + 1):
            if i != self.width:
                text = self.font.render(str(i), 2, (255, 255, 255))
                x, y = self.Vcoords((i, -1))
                textpos = text.get_rect(centerx=x + 25, centery=y + 25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255, 255, 255), self.Vcoords((i, 0)), self.Vcoords((i, self.hight)))

        for j in range(self.hight + 1):
            if j != self.hight:
                text = self.font.render(str(j), 2, (255, 255, 255))
                x, y = self.Vcoords((-1, j))
                textpos = text.get_rect(centerx=x + 25, centery=y + 25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255, 255, 255), self.Vcoords((0, j)), self.Vcoords((self.width, j)))

        for b in self.blocks:
            start = self.Vcoords(b)

            pygame.draw.rect(self.window, (255, 0, 0), (start[0] + 10, start[1] + 10, 25, 25), 10)

        # initial
        color = (0, 255, 0) if self.initial != trace[-1] else (255, 255, 0)
        text = self.font.render("#", 2, color)
        x, y = self.Vcoords(self.initial)
        textpos = text.get_rect(centerx=x + 25, centery=y + 25)
        self.window.blit(text, textpos)

        # goal
        color = (0, 255, 0) if self.goal != trace[-1] else (255, 255, 0)
        text = self.font.render("$", 2, color)
        x, y = self.Vcoords(self.goal)
        textpos = text.get_rect(centerx=x + 20, centery=y + 20)
        self.window.blit(text, textpos)

        # trace
        for p in trace[1:-1]:
            text = self.font.render("+", 2, (0, 255, 0))
            x, y = self.Vcoords(p)
            textpos = text.get_rect(centerx=x + 20, centery=y + 20)
            self.window.blit(text, textpos)

        # last
        if trace[-1] not in [self.initial, self.goal]:
            text = self.font.render("+", 2, (255, 255, 0))
            x, y = self.Vcoords(trace[-1])
            textpos = text.get_rect(centerx=x + 20, centery=y + 20)
            self.window.blit(text, textpos)

        # draw it to the screen
        pygame.display.flip()

    def wait_game(self):
        stop = False
        while not stop:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pass
                    sys.exit(0)
                elif event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN:
                    stop = True;
                    break;
                else:
                    # print event
                    pass


class KColoring(Problem):
    def __init__(self, sample=None):
        if sample:
            g = sample
        else:
            g = Sample_Basic()
        self.initial = g.initial
        self.points = g.points
        self.links = g.links
        self.colors_list = g.colors_list
        self.colors_list.extend([None] * ((len(g.points) - len(g.colors_list)) + 1))
        self.colors_definition = g.colors_definition
        self.positions = g.positions

    window = None  # graphical window

    class Sample_Basic:
        points = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        links = {1: [2, 5, 6], 2: [1, 3, 7], 3: [2, 8, 4], 4: [3, 9, 5], 5: [4, 10, 1], 6: [1, 8, 9], 7: [2, 9, 10],
                 8: [3, 6, 10], 9: [4, 7, 6], 10: [5, 7, 8]}
        positions = {1: (0, 4), 2: (4, 0), 3: (2, -4), 4: (-2, -4), 5: (-4, 0), 6: (0, 2), 7: (2, 0), 8: (1, -2),
                     9: (-1, -2), 10: (-2, 0)}
        initial = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0}
        colors_definition = {None: (255, 255, 255), "red": (255, 0, 0), "green": (0, 255, 0), "blue": (0, 0, 255),
                             "yellow": (255, 255, 0), "blue-sky": (0, 255, 255), "pinky": (255, 0, 255)}
        colors_list = [None, "blue", "red", "green", "yellow", "pinky", "blue-sky"]

    class Sample_1(Sample_Basic):  # 15
        points = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
        links = {1: [2, 5, 11, 15, 6], 2: [1, 3, 11, 12, 7], 3: [2, 4, 12, 13, 8], 4: [3, 5, 13, 14, 9],
                 5: [4, 1, 14, 15, 10], 6: [8, 9, 1, 11], 7: [9, 10, 2, 12], 8: [6, 10, 3, 13], 9: [7, 6, 4, 14],
                 10: [7, 8, 5, 15], 11: [2, 1, 6], 12: [2, 3, 7], 13: [3, 4, 8], 14: [4, 5, 9], 15: [5, 1, 10]}
        positions = {1: (0, 4), 2: (4, 0), 3: (2, -4), 4: (-2, -4), 5: (-4, 0), 6: (0, 2), 7: (2, 0), 8: (1, -2),
                     9: (-1, -2), 10: (-2, 0), 11: (4, 4), 12: (6, -4), 13: (0, -6), 14: (-6, -4), 15: (-4, 4)}
        initial = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0, 11: 0, 12: 0, 13: 0, 14: 0, 15: 0}
        colors_definition = {None: (255, 255, 255), "red": (255, 0, 0), "green": (0, 255, 0), "blue": (0, 0, 255),
                             "yellow": (255, 255, 0), "blue-sky": (0, 255, 255), "pinky": (255, 0, 255)}
        colors_list = [None, "blue", "red", "green", "yellow", "pinky", "blue-sky"]

    class Sample_2(Sample_Basic):
        points = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        links = {1: [2, 5], 2: [1, 3], 3: [2, 4], 4: [3, 5], 5: [4, 1], 6: [8, 9], 7: [9, 10], 8: [6, 10], 9: [7, 6],
                 10: [7, 8]}
        positions = {1: (0, 4), 2: (4, 0), 3: (2, -4), 4: (-2, -4), 5: (-4, 0), 6: (0, 2), 7: (2, 0), 8: (1, -2),
                     9: (-1, -2), 10: (-2, 0)}
        initial = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0}
        colors_definition = {None: (255, 255, 255), "red": (255, 0, 0), "green": (0, 255, 0), "blue": (0, 0, 255),
                             "yellow": (255, 255, 0), "blue-sky": (0, 255, 255), "pinky": (255, 0, 255)}
        colors_list = [None, "blue", "red", "green", "yellow", "pinky", "blue-sky"]

    class Sample_3(Sample_Basic):  # 15
        points = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
        links = {1: [2, 5, 11, 15, 6], 2: [1, 3, 11, 12, 7], 3: [2, 4, 12, 13, 8], 4: [3, 5, 13, 14, 9],
                 5: [4, 1, 14, 15, 10], 6: [8, 9, 1, 11], 7: [9, 10, 2, 7], 8: [6, 10, 3], 9: [7, 6, 4, 14],
                 10: [7, 8, 5], 11: [2, 1, 6], 12: [2, 3, 7], 13: [3, 4], 14: [4, 5, 9], 15: [5, 1]}
        positions = {1: (0, 4), 2: (4, 0), 3: (2, -4), 4: (-2, -4), 5: (-4, 0), 6: (0, 2), 7: (2, 0), 8: (1, -2),
                     9: (-1, -2), 10: (-2, 0), 11: (4, 4), 12: (6, -4), 13: (0, -6), 14: (-6, -4), 15: (-4, 4)}
        initial = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0, 11: 0, 12: 0, 13: 0, 14: 0, 15: 0}
        colors_definition = {None: (255, 255, 255), "red": (255, 0, 0), "green": (0, 255, 0), "blue": (0, 0, 255),
                             "yellow": (255, 255, 0), "blue-sky": (0, 255, 255), "pinky": (255, 0, 255)}
        colors_list = [None, "blue", "red", "green", "yellow", "pinky", "blue-sky"]

    def successors(self, coloring):

        def possible(color, coloring):
            possible = False
            for p in self.points:
                if not coloring[p]:
                    used_colors = []
                    for linked_point in self.links[p]:
                        if coloring[linked_point]:
                            used_colors.append(coloring[linked_point])
                    if color in used_colors:
                        continue;
                    else:
                        possible = True
                        break
            return possible

        succ = []
        current_color = max(set(coloring.values()))
        if not possible(current_color, coloring) or current_color == 0:
            current_color += 1

        non_colored = []
        for point in self.points:
            if not coloring[point]:
                non_colored.append(point)

        for point in non_colored:
            used_colors = []
            for linked_point in self.links[point]:
                if coloring[linked_point]:
                    used_colors.append(coloring[linked_point])

            if current_color not in used_colors:
                new_coloring = dict(coloring)
                new_coloring[point] = current_color;
                succ.append(new_coloring)

        return succ

    def h(self, coloring):  # rest to colorize
        return coloring.values().count(0)

    def g(self, coloring):  # number of colors used
        return len(set(coloring.values()) - {0})

    def f(self, coloring):
        return self.g(coloring) + self.h(coloring)  # h=0 => BEST MOVE #g=0 => FIRSt admissible move

    def objective(self, coloring):
        return (coloring.values().count(0) == 0)

    def init_game(self):
        pygame.init()
        WX = WY = 600
        self.window = pygame.display.set_mode((WX, WY))
        if pygame.font:
            self.font = pygame.font.Font(None, 30)

    def Vcoords(self, Rcoords):
        return (Rcoords[0] * 45 + 300, 600 - (Rcoords[1] * 45 + 300))

    def draw(self, coloring, step=1, steps_number=1):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0
        #####
        """
        text = self.font.render("used colors = %d" % (self.g(coloring)), 1, (50, 255, 50))
        x,y=(25,25)
        textpos = text.get_rect(centerx=x,centery=y)
        self.window.blit(text, textpos)

        text = self.font.render("steps =  %d" % (step), 1, (50, 255, 50))
        x,y=(25*step+50,50)
        textpos = text.get_rect(centerx=x,centery=y)
        self.window.blit(text, textpos)
        """

        for (source, destinations) in self.links.items():
            source_position = self.Vcoords(self.positions[source])
            for destination in destinations:
                destination_position = self.Vcoords(self.positions[destination])

                pygame.draw.line(self.window, self.colors_definition[None], source_position, destination_position)
        for p in self.points:
            pygame.draw.circle(self.window, self.colors_definition[self.colors_list[coloring[p]]],
                               self.Vcoords(self.positions[p]), 20, 20)
            text = self.font.render(str(p), 2, (0, 0, 0))
            x, y = self.Vcoords(self.positions[p])
            textpos = text.get_rect(centerx=x, centery=y)
            self.window.blit(text, textpos)

        # draw it to the screen
        pygame.display.flip()

    def wait_game(self):
        stop = False
        while not stop:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pass
                    sys.exit(0)
                elif event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN:
                    stop = True;
                    break;
                else:
                    # print event
                    pass


def Branch_and_Bound(problem):
    cpt = 0;
    success = False
    configs_fifo = [(problem.f(problem.initial), [problem.initial])]
    used = []
    tree = {}
    while (configs_fifo):

        cpt += 1;

        steps = configs_fifo.pop()[1]
        config = steps[-1]
        problem.init_game()
        problem.draw(config)
        problem.wait_game()

        success = problem.objective(config)
        if success:
            break
        if config not in used:
            used.append(config)
            tree[str(config)] = []
            print
            print str(config), ">>",
            for s in problem.successors(config):
                p = problem.f(s)
                tree[str(config)].append((p, str(s)))
                print " && ", str(s),
                i = 0;
                if configs_fifo:
                    while (i < len(configs_fifo)):
                        if p >= configs_fifo[i][0]:
                            break;
                        i += 1;
                new_steps = list(steps)
                new_steps.append(s)
                configs_fifo.insert(i, (p, new_steps))
    return (success, cpt, steps, tree)


def draw_tree(tree):
    print tree;


if __name__ == '__main__':
    choice = input("which problem you want to resolve?\n 1.K-coloring \n 2.Labyrinth \n 3.PVC\n\n choice=?")
    if choice == 1:
        kcoloring = KColoring(KColoring.Sample_3())
        success, cpt, steps, tree = Branch_and_Bound(kcoloring)
        coloring = steps[-1]
        print success, " after %d iterations" % cpt
        print "the best coloring with %d colors is " % kcoloring.g(coloring), coloring
        draw_tree(tree)
        # raw_input()
        cpt = 0

        foldername = "KColor_" + str(abs(hash(str(kcoloring.links))))
        if not os.path.exists("./" + foldername + "/"):
            os.mkdir("./" + foldername + "/")
        os.chdir("./" + foldername + "/")
        for step in steps:
            kcoloring.draw(step)
            pygame.image.save(kcoloring.window, "./%d.jpeg" % cpt)
            kcoloring.wait_game()
            cpt += 1
    elif choice == 2:
        labyrinth = Labyrinth(Labyrinth.Sample_1)
        success, cpt, steps, tree = Branch_and_Bound(labyrinth)
        print success, " after %d iterations" % cpt
        print "player moves = ", steps
        draw_tree(tree)
        labyrinth.draw_trace(steps)
        pygame.image.save(labyrinth.window, "./Labyrinth_%d.jpeg" % abs(hash(str(steps))))
        labyrinth.wait_game()

    elif choice == 3:
        pvc = PVC()
        success, cpt, steps, tree = Branch_and_Bound(pvc)
        chemin = steps[-1]

        print success, " after %d iterations" % cpt
        print "the best way with the distance %d  is " % pvc.g(chemin), chemin
        draw_tree(tree)
        # raw_input()
        cpt = 0

        foldername = "PVC_" + str(abs(hash(str(pvc.distances))))
        if not os.path.exists("./" + foldername + "/"):
            os.mkdir("./" + foldername + "/")
        os.chdir("./" + foldername + "/")
        for step in steps:
            pvc.init_game()
            pvc.draw(step)
            pygame.image.save(pvc.window, "./%d.jpeg" % cpt)
            pvc.wait_game()
            cpt += 1
