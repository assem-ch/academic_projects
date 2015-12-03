
#MIN,Max Value for BB limits for a general problem
MIN,MAX =  0,9999999



import pygame,sys,os,random,math,pickle



class Problem:
    
    def __init__(self,sample=None):
        self.initial=None
        pass
    
    def successors(self,coloring):  
        return []

                
    def h(self,config): #rest to colorize
        return 0
    
    def g(self,config): # number of colors used
        return 0
        
    def f(self,config):
        return self.g(config)+self.h(config)
     
    
    def  objective(self,config):
        return (config.values().count(0)==0)
    pass

    def Max(self):
        return MAX;
    
    def Min(self):
        return MIN;


def fill(grid,w,h,piece,x,y):
    new_grid = pickle.copy(grid)
    for point in piece:
        if grid[x+point[0]][y+point[1]]:
            return False
        else:
            new_grid[x+point[0]][y+point[1]]=1;
    return new_grid



class Ominous(Problem):
    def __init__(self,info):
        self.width=info.width
        self.hight=info.hight
        self.N=info.N
        self.selected_piece= info.selected_piece
        self.initial=[[0 for x in range(5)] for x in range(5)]
        
    
    window=None


    
    def successors(self,grid):
        
        succ=[]
        #test borns
        player_={}
        player_["up"]=(player[0],player[1]-1) if player[1] else None
        player_["down"]=(player[0],player[1]+1) if self.hight-player[1]-1 else None
        player_["right"]=(player[0]+1,player[1]) if self.width-player[0]-1 else None
        player_["left"]=(player[0]-1,player[1]) if player[0] else None
        #test_blocks
        for p in player_.values():
            if p and p not in self.blocks:
                succ.append(p)
                
        return succ

    def g(self,player):
        return math.sqrt(math.pow(2,(player[0]-self.initial[0]))+math.pow(2,(player[1]-self.initial[1])))
        
    def h(self,player):
        return math.sqrt(math.pow(2,(player[0]-self.goal[0]))+math.pow(2,(player[1]-self.goal[1])))
        
    def f(self,config):
        return 0*self.g(config)+self.h(config)
    
    def objective(self,player):
        return player==self.goal
    
    def init_game(self):
        pygame.init() 
        WX = WY = 600                 
        self.window = pygame.display.set_mode((WX, WY))
        if pygame.font:
                self.font = pygame.font.Font(None, 30)

        
    def Vcoords(self,Rcoords):
        return (Rcoords[0]*45+100,Rcoords[1]*45+100)
    
    def draw(self,trace):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0
        
        for i in range(self.width+1):
            if i!=self.width:
                text = self.font.render(str(i), 2,(255,255,255))
                x,y=self.Vcoords((i,-1))
                textpos = text.get_rect(centerx=x+25,centery=y+25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255,255,255),self.Vcoords((i,0)),self.Vcoords((i,self.hight)))

        for j in range(self.hight+1):
            if j!=self.hight:
                text = self.font.render(str(j), 2,(255,255,255))
                x,y=self.Vcoords((-1,j))
                textpos = text.get_rect(centerx=x+25,centery=y+25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255,255,255),self.Vcoords((0,j)),self.Vcoords((self.width,j)))
            
        
        for b in self.blocks:
            start=self.Vcoords(b)

            pygame.draw.rect(self.window,(255,0,0),(start[0]+10,start[1]+10,25,25),10)
            
        #initial
        color=(0,255, 0) 
        text = self.font.render("#", 2, color)
        x,y=self.Vcoords(self.initial)
        textpos = text.get_rect(centerx=x+25,centery=y+25)
        self.window.blit(text, textpos)

        #goal
        color=(0,255, 0) 
        text = self.font.render("$", 2, color)
        x,y=self.Vcoords(self.goal)
        textpos = text.get_rect(centerx=x+20,centery=y+20)
        self.window.blit(text, textpos)
        

        
        #last
        text = self.font.render("+", 2, (255,255, 0))
        x,y=self.Vcoords(trace)
        textpos = text.get_rect(centerx=x+20,centery=y+20)
        self.window.blit(text, textpos)
        
            
       
       

        #draw it to the screen
        pygame.display.flip() 
    
    def draw_trace(self,trace):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0
        
        for i in range(self.width+1):
            if i!=self.width:
                text = self.font.render(str(i), 2,(255,255,255))
                x,y=self.Vcoords((i,-1))
                textpos = text.get_rect(centerx=x+25,centery=y+25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255,255,255),self.Vcoords((i,0)),self.Vcoords((i,self.hight)))

        for j in range(self.hight+1):
            if j!=self.hight:
                text = self.font.render(str(j), 2,(255,255,255))
                x,y=self.Vcoords((-1,j))
                textpos = text.get_rect(centerx=x+25,centery=y+25)
                self.window.blit(text, textpos)
            pygame.draw.line(self.window, (255,255,255),self.Vcoords((0,j)),self.Vcoords((self.width,j)))
            
        
        for b in self.blocks:
            start=self.Vcoords(b)

            pygame.draw.rect(self.window,(255,0,0),(start[0]+10,start[1]+10,25,25),10)
            
        #initial
        color=(0,255, 0) if self.initial!=trace[-1] else (255,255, 0)
        text = self.font.render("#", 2, color)
        x,y=self.Vcoords(self.initial)
        textpos = text.get_rect(centerx=x+25,centery=y+25)
        self.window.blit(text, textpos)

        #goal
        color=(0,255, 0) if self.goal!=trace[-1] else (255,255, 0)
        text = self.font.render("$", 2, color)
        x,y=self.Vcoords(self.goal)
        textpos = text.get_rect(centerx=x+20,centery=y+20)
        self.window.blit(text, textpos)
        
        #trace
        for p in trace[1:-1]:
            text = self.font.render("+", 2, (0,255, 0))
            x,y=self.Vcoords(p)
            textpos = text.get_rect(centerx=x+20,centery=y+20)
            self.window.blit(text, textpos)
        
        #last
        if trace[-1] not in [self.initial,self.goal]:
            text = self.font.render("+", 2, (255,255, 0))
            x,y=self.Vcoords(trace[-1])
            textpos = text.get_rect(centerx=x+20,centery=y+20)
            self.window.blit(text, textpos)
        
            
       
       

        #draw it to the screen
        pygame.display.flip() 
        
        
    def wait_game(self):
        stop=False
        while not stop: 
           for event in pygame.event.get(): 
              if event.type == pygame.QUIT: 
                 pass
                 sys.exit(0) 
              elif event.type==pygame.KEYDOWN or event.type==pygame.MOUSEBUTTONDOWN:
                  stop=True;
                  break;
              else: 
                 #print event
                 pass


def Branch_and_Bound(problem):
    cpt=0;success=False
    configs_fifo=[(problem.f(problem.initial),[problem.initial])]
    used=[]
    tree={}
    while(configs_fifo):

        cpt+=1;
        
        steps=configs_fifo.pop()[1]
        config=steps[-1]
        problem.init_game()
        problem.draw(config)
        problem.wait_game()

        success=problem.objective(config)
        if success:
            break
        if config not in used:
            used.append(config)
            tree[str(config)]=[]
            #print
            #print str(config),">>",
            for s in problem.successors(config):
                    p=problem.f(s)
                    tree[str(config)].append((p,str(s)))
                    #print " && ",str(s),
                    i=0;
                    if configs_fifo:
                        while(i<len(configs_fifo)):
                            if p>=configs_fifo[i][0]:
                                break;
                            i+=1;
                    new_steps=list(steps)
                    new_steps.append(s)        
                    configs_fifo.insert(i,(p,new_steps))
    return (success,cpt,steps,tree)
               



def draw_tree(tree):
    print tree;
    
    
    



    


        
        
    
    
if __name__ == '__main__':
        labyrinth=Labyrinth(Labyrinth.Sample_1)
        success,cpt,steps,tree =Branch_and_Bound(labyrinth)
        print success," after %d iterations" % cpt
        print "player moves = ",steps
        draw_tree(tree)
        labyrinth.draw_trace(steps)
        pygame.image.save(labyrinth.window,"./Labyrinth_%d.jpeg" % abs(hash(str(steps))))
        labyrinth.wait_game()

    
