'''
Created on Mar 26, 2011
@author: assem,chelli


'''

# MIN,Max Value for BB limits for a general problem
MIN, MAX = 0, 9999999

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
                     (2, 4): 200, (2, 5): 250, (3, 2): 400, (3, 4): 400, (3, 1): 130, (4, 1): 290, (4, 3): 400,
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
        # return (set(self.towns)==set(self.visited(chemin))) and chemin[0][0]==chemin[-1][1] #hamiltoian
        return (set(self.towns) == set(self.visited(chemin)))

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
            # print str(config),">>",
            for s in problem.successors(config):
                p = problem.f(s)
                tree[str(config)].append((p, str(s)))
                # print " && ",str(s),
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
