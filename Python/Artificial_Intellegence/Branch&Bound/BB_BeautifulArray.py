
#MIN,Max Value for BB limits for a general problem
MIN,MAX =  0,9999999


class Problem:
    def __init__(self, array = [3,0,2,2], N = 4, K = 1, L = 2 ):
        self.initial = (array, 0)
        self.min =  min(self.initial)
        self.max = max(self.initial)
        self.N = N
        self.K = K
        self.L = L

    
    def successors(self,config):  
        #choice 1
        for i in xrange(self.N):
            for j in xrange(self.N):
                if i == j:
                    continue
                child = list(config[0])
                if child[i]>=self.max or child[j]<=self.min:
                    continue
                child[i]+=1
                child[j]-=1
                yield child, config[1]+self.K
        
        # choice 2
        for i in xrange(self.N):
            child = list( config[0])
            child[i]+=1
            yield child, config[1]+ self.L



    
    def g(self,config): # number of colors used
        return config[1]

    def h(self,config): #rest to colorize
        return 0
        
    def f(self,config):
        return self.g(config)+self.h(config)
     
    
    def  objective(self,config):
        return len(set(config[0])) <=1


    def Max(self):
        return MAX;
    
    def Min(self):
        return MIN;








def Branch_and_Bound(problem):
    cpt=0;success=False
    configs_fifo=[(problem.f(problem.initial),[problem.initial])]
    used=[]
    tree={}
    while(configs_fifo):

        cpt+=1;

        steps=configs_fifo.pop()[1]
        config=steps[-1]

        success=problem.objective(config)
        if success:
            break
        if config not in used:
            print cpt, config
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
                    print cpt,i,p,s
    return (success,cpt,steps,tree)



def draw_tree(tree):
    print tree;

if __name__ == '__main__':
        problem=Problem()
        success,cpt,steps,tree =Branch_and_Bound(problem)
        print success," after %d iterations" % cpt
        print "player moves = ",steps
        #print "tree =", tree



