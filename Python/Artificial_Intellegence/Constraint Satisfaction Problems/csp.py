"""CSP (Constraint Satisfaction Problems) problems and solvers. (Chapter 5)."""

# todo: k-coloring
# todo: find all solutions
# todo: 



from __future__ import generators

import types,copy,pygame,sys

colors=[(255,0,0),(0,255,0),(0,0,255),(255,255,0),(255,0,255),(0,255,255),(255,255,255),(127,50,0),(0,50,127),(0,127,50),(127,127,50),(127,50,127),(50,127,127),(127,255,127)]

def count_if(predicate, seq):
    """Count the number of elements of seq for which the predicate is true.
    >>> count_if(callable, [42, None, max, min])
    2
    """
    f = lambda count, x: count + (not not predicate(x))
    return reduce(f, seq, 0)

def argmin_random_tie(seq, fn):
    """Return an element with lowest fn(seq[i]) score; break ties at random.
    Thus, for all s,f: argmin_random_tie(s, f) in argmin_list(s, f)"""
    best_score = fn(seq[0]); n = 0
    for x in seq:
        x_score = fn(x)
        if x_score < best_score:
            best, best_score = x, x_score; n = 1
        elif x_score == best_score:
            n += 1
            if random.randrange(n) == 0:
                    best = x
    return best


def update(x, **entries):
    """Update a dict; or an object with slots; according to entries.
    >>> update({'a': 1}, a=10, b=20)
    {'a': 10, 'b': 20}
    >>> update(Struct(a=1), a=10, b=20)
    Struct(a=10, b=20)
    """
    if isinstance(x, dict):
        x.update(entries)   
    else:
        x.__dict__.update(entries) 
    return x 

class DefaultDict(dict):
    """Dictionary with a default value for unknown keys."""
    def __init__(self, default):
        self.default = default

    def __getitem__(self, key):
        if key in self: return self.get(key)
        return self.setdefault(key, copy.deepcopy(self.default))
    
    def __copy__(self):
        copy = DefaultDict(self.default)
        copy.update(self)
        return copy

class Problem:
    """The abstract class for a formal problem.  You should subclass this and
    implement the method successor, and possibly __init__, goal_test, and
    path_cost. Then you will create instances of your subclass and solve them
    with the various search functions."""

    def __init__(self, initial, goal=None):
        """The constructor specifies the initial state, and possibly a goal
        state, if there is a unique goal.  Your subclass's constructor can add
        other arguments."""
        self.initial = initial; self.goal = goal
        
    def successor(self, state):
        """Given a state, return a sequence of (action, state) pairs reachable
        from this state. If there are many successors, consider an iterator
        that yields the successors one at a time, rather than building them
        all at once. Iterators will work fine within the framework."""
        abstract
    
    def goal_test(self, state):
        """Return True if the state is a goal. The default method compares the
        state to self.goal, as specified in the constructor. Implement this
        method if checking against a single self.goal is not enough."""
        return state == self.goal
    
    def path_cost(self, c, state1, action, state2):
        """Return the cost of a solution path that arrives at state2 from
        state1 via action, assuming cost c to get up to state1. If the problem
        is such that the path doesn't matter, this function will only look at
        state2.  If the path does matter, it will consider c and maybe state1
        and action. The default method costs 1 for every step in the path."""
        return c + 1

    def value(self):
        """For optimization problems, each state has a value.  Hill-climbing
        and related algorithms try to maximize this value."""
        abstract

class CSP(Problem):
    """This class describes finite-domain Constraint Satisfaction Problems.
    A CSP is specified by the following three inputs:
        vars        A list of variables; each is atomic (e.g. int or string).
        domains     A dict of {var:[possible_value, ...]} entries.
        neighbors   A dict of {var:[var,...]} that for each variable lists
                    the other variables that participate in constraints.
        constraints A function f(A, a, B, b) that returns true if neighbors
                    A, B satisfy the constraint when they have values A=a, B=b
    In the textbook and in most mathematical definitions, the
    constraints are specified as explicit pairs of allowable values,
    but the formulation here is easier to express and more compact for
    most cases. (For example, the n-Queens problem can be represented
    in O(n) space using this notation, instead of O(N^4) for the
    explicit representation.) In terms of describing the CSP as a
    problem, that's all there is.

    However, the class also supports data structures and methods that help you
    solve CSPs by calling a search function on the CSP.  Methods and slots are
    as follows, where the argument 'a' represents an assignment, which is a
    dict of {var:val} entries:
        assign(var, val, a)     Assign a[var] = val; do other bookkeeping
        unassign(var, a)        Do del a[var], plus other bookkeeping
        nconflicts(var, val, a) Return the number of other variables that
                                conflict with var=val
        curr_domains[var]       Slot: remaining consistent values for var
                                Used by constraint propagation routines.
    The following methods are used only by graph_search and tree_search:
        succ()                  Return a list of (action, state) pairs
        goal_test(a)            Return true if all constraints satisfied
    The following are just for debugging purposes:
        nassigns                Slot: tracks the number of assignments made
        display(a)              Print a human-readable representation
        """

    def __init__(self, vars, domains, neighbors, constraints):
        "Construct a CSP problem. If vars is empty, it becomes domains.keys()."
        vars = vars or domains.keys()
        update(self, vars=vars, domains=domains,
               neighbors=neighbors, constraints=constraints,
               initial={}, curr_domains=None, pruned=None, nassigns=0)
        
        
    def assign(self, var, val, assignment):
        """Add {var: val} to assignment; Discard the old value if any.
        Do bookkeeping for curr_domains and nassigns."""
        self.nassigns += 1
        assignment[var] = val
        
        if self.curr_domains:
            if self.fc:
                self.forward_check(var, val, assignment)
            if self.mac:
                AC3(self, [(Xk, var) for Xk in self.neighbors[var]])
                

    def unassign(self, var, assignment):
        """Remove {var: val} from assignment; that is backtrack.
        DO NOT call this if you are changing a variable to a new value;
        just call assign for that."""
        if var in assignment:
            # Reset the curr_domain to be the full original domain
            if self.curr_domains:
                self.curr_domains[var] = self.domains[var][:]
            del assignment[var]

    def nconflicts(self, var, val, assignment):
        "Return the number of conflicts var=val has with other variables."
        # Subclasses may implement this more efficiently
        def conflict(var2):
            val2 = assignment.get(var2, None)
            return val2 is not None and not self.constraints(var, val, var2, val2)
        print count_if(conflict, self.neighbors[var])
        return count_if(conflict, self.neighbors[var])

    def forward_check(self, var, val, assignment):
        "Do forward checking (current domain reduction) for this assignment."
        if self.curr_domains:
            # Restore prunings from previous value of var
            for (B, b) in self.pruned[var]:
                self.curr_domains[B].append(b)
            self.pruned[var] = []
            # Prune any other B=b assignement that conflict with var=val
            for B in self.neighbors[var]:
                if B not in assignment:
                    for b in self.curr_domains[B][:]:
                        if not self.constraints(var, val, B, b):
                            self.curr_domains[B].remove(b)
                            self.pruned[var].append((B, b))

    def display(self, assignment):
        "Show a human-readable representation of the CSP."
        # Subclasses can print in a prettier way, or display with a GUI
        print 'CSP:', self, 'with assignment:', assignment

    ## These methods are for the tree and graph search interface:

    def succ(self, assignment):
        "Return a list of (action, state) pairs."
        if len(assignment) == len(self.vars):
            return []
        else:
            var = find_if(lambda v: v not in assignment, self.vars)
            result = []
            for val in self.domains[var]:
                if self.nconflicts(self, var, val, assignment) == 0:
                    a = assignment.copy; a[var] = val
                    result.append(((var, val), a))
            return result

    def goal_test(self, assignment):
        "The goal is to assign all vars, with all constraints satisfied."
        return (len(assignment) == len(self.vars) and
                every(lambda var: self.nconflicts(var, assignment[var],
                                                  assignment) == 0,
                      self.vars))

    ## This is for min_conflicts search

    def conflicted_vars(self, current):
        "Return a list of variables in current assignment that are in conflict"
        return [var for var in self.vars
                if self.nconflicts(var, current[var], current) > 0]

#______________________________________________________________________________
# CSP Backtracking Search
                
def backtracking_search(csp, mcv=False, lcv=False, fc=False, mac=False):
    """Set up to do recursive backtracking search. Allow the following options:
    mcv - If true, use Most Constrained Variable Heuristic
    lcv - If true, use Least Constraining Value Heuristic
    fc  - If true, use Forward Checking
    mac - If true, use Maintaining Arc Consistency.              [Fig. 5.3]
    >>> backtracking_search(australia)
    {'WA': 'B', 'Q': 'B', 'T': 'B', 'V': 'B', 'SA': 'G', 'NT': 'R', 'NSW': 'R'}
    """
    if fc or mac:
        csp.curr_domains, csp.pruned = {}, {}
        for v in csp.vars:
            csp.curr_domains[v] = csp.domains[v][:]
            csp.pruned[v] = []
    update(csp, mcv=mcv, lcv=lcv, fc=fc, mac=mac)
    return recursive_backtracking({}, csp)

def recursive_backtracking(assignment, csp):
    """Search for a consistent assignment for the csp.
    Each recursive call chooses a variable, and considers values for it."""
    if len(assignment) == len(csp.vars):
        print assignment
        return assignment
    var = select_unassigned_variable(assignment, csp)
    for val in order_domain_values(var, assignment, csp):
        if csp.fc or csp.nconflicts(var, val, assignment) == 0:
            csp.assign(var, val, assignment)
            
            result = recursive_backtracking(assignment, csp)
            if result is not None:
                
                return result
        csp.unassign(var, assignment)
    return None

def select_unassigned_variable(assignment, csp):
    "Select the variable to work on next.  Find"
    if csp.mcv: # Most Constrained Variable 
        unassigned = [v for v in csp.vars if v not in assignment] 
        return argmin_random_tie(unassigned,
                     lambda var: -num_legal_values(csp, var, assignment))
    else: # First unassigned variable
        for v in csp.vars:
            if v not in assignment:
                return v

def order_domain_values(var, assignment, csp):
    "Decide what order to consider the domain variables."
    if csp.curr_domains:
        domain = csp.curr_domains[var]
    else:
        domain = csp.domains[var][:]
    if csp.lcv:
        # If LCV is specified, consider values with fewer conflicts first
        key = lambda val: csp.nconflicts(var, val, assignment)
        domain.sort(lambda(x,y): cmp(key(x), key(y)))
    while domain:
        yield domain.pop()

def num_legal_values(csp, var, assignment):
    if csp.curr_domains:
        return len(csp.curr_domains[var])
    else:
        return count_if(lambda val: csp.nconflicts(var, val, assignment) == 0,
                        csp.domains[var])

#______________________________________________________________________________
# Constraint Propagation with AC-3

def AC3(csp, queue=None):
    """[Fig. 5.7]"""
    if queue is None:
        queue = [(Xi, Xk) for Xi in csp.vars for Xk in csp.neighbors[Xi]]
    while queue:
        (Xi, Xj) = queue.pop()
        if remove_inconsistent_values(csp, Xi, Xj):
            for Xk in csp.neighbors[Xi]:
                queue.append((Xk, Xi))

def remove_inconsistent_values(csp, Xi, Xj):
    "Return true if we remove a value."
    removed = False
    for x in csp.curr_domains[Xi][:]:
        # If Xi=x conflicts with Xj=y for every possible y, eliminate Xi=x
        if every(lambda y: not csp.constraints(Xi, x, Xj, y),
                csp.curr_domains[Xj]):
            csp.curr_domains[Xi].remove(x)
            removed = True
    return removed

#______________________________________________________________________________
# Min-conflicts hillclimbing search for CSPs

def min_conflicts(csp, max_steps=1000000): 
    """Solve a CSP by stochastic hillclimbing on the number of conflicts."""
    # Generate a complete assignement for all vars (probably with conflicts)
    current = {}; csp.current = current
    for var in csp.vars:
        val = min_conflicts_value(csp, var, current)
        csp.assign(var, val, current)
    # Now repeapedly choose a random conflicted variable and change it
    for i in range(max_steps):
        conflicted = csp.conflicted_vars(current)
        if not conflicted:
            return current
        var = random.choice(conflicted)
        val = min_conflicts_value(csp, var, current)
        csp.assign(var, val, current)
    return None

def min_conflicts_value(csp, var, current):
    """Return the value that will give var the least number of conflicts.
    If there is a tie, choose at random."""
    return argmin_random_tie(csp.domains[var],
                             lambda val: csp.nconflicts(var, val, current)) 

#______________________________________________________________________________
# Map-Coloring Problems

class UniversalDict:
    """A universal dict maps any key to the same value. We use it here
    as the domains dict for CSPs in which all vars have the same domain.
    >>> d = UniversalDict(42)
    >>> d['life']
    42
    """
    def __init__(self, value): self.value = value
    def __getitem__(self, key): return self.value
    def __repr__(self): return '{Any: %r}' % self.value

def different_values_constraint(A, a, B, b):
    "A constraint saying two neighboring variables must differ in value."
    return a != b

def MapColoringCSP(colors, neighbors):
    """Make a CSP for the problem of coloring a map with different colors
    for any two adjacent regions.  Arguments are a list of colors, and a
    dict of {region: [neighbor,...]} entries.  This dict may also be
    specified as a string of the form defined by parse_neighbors"""

    if isinstance(neighbors, str):
        neighbors = parse_neighbors(neighbors)     
    return CSP(neighbors.keys(), UniversalDict(colors), neighbors,
               different_values_constraint)

def parse_neighbors(neighbors, vars=[]):
    """Convert a string of the form 'X: Y Z; Y: Z' into a dict mapping
    regions to neighbors.  The syntax is a region name followed by a ':'
    followed by zero or more region names, followed by ';', repeated for
    each region name.  If you say 'X: Y' you don't need 'Y: X'.
    >>> parse_neighbors('X: Y Z; Y: Z')
    {'Y': ['X', 'Z'], 'X': ['Y', 'Z'], 'Z': ['X', 'Y']}
    """
    dict = DefaultDict([])
    for var in vars:
        dict[var] = []
    specs = [spec.split(':') for spec in neighbors.split(';')]
    for (A, Aneighbors) in specs:
        A = A.strip();
        dict.setdefault(A, [])
        for B in Aneighbors.split():
            dict[A].append(B)
            dict[B].append(A)
    return dict

australia = MapColoringCSP(list('RGB'),
                           'SA: WA NT Q NSW V; NT: WA Q; NSW: Q V; T: ')
    
usa = MapColoringCSP(list('RGBY'),
        """WA: OR ID; OR: ID NV CA; CA: NV AZ; NV: ID UT AZ; ID: MT WY UT;
        UT: WY CO AZ; MT: ND SD WY; WY: SD NE CO; CO: NE KA OK NM; NM: OK TX;
        ND: MN SD; SD: MN IA NE; NE: IA MO KA; KA: MO OK; OK: MO AR TX;
        TX: AR LA; MN: WI IA; IA: WI IL MO; MO: IL KY TN AR; AR: MS TN LA;
        LA: MS; WI: MI IL; IL: IN; IN: KY; MS: TN AL; AL: TN GA FL; MI: OH;
        OH: PA WV KY; KY: WV VA TN; TN: VA NC GA; GA: NC SC FL;
        PA: NY NJ DE MD WV; WV: MD VA; VA: MD DC NC; NC: SC; NY: VT MA CA NJ;
        NJ: DE; DE: MD; MD: DC; VT: NH MA; MA: NH RI CT; CT: RI; ME: NH;
        HI: ; AK: """)
#______________________________________________________________________________
# n-Queens Problem

def queen_constraint(A, a, B, b):
    """Constraint is satisfied (true) if A, B are really the same variable,
    or if they are not in the same row, down diagonal, or up diagonal."""
    return A == B or (a != b and A + a != B + b and A - a != B - b)

class NQueensCSP(CSP):
    """Make a CSP for the nQueens problem for search with min_conflicts.
    Suitable for large n, it uses only data structures of size O(n).
    Think of placing queens one per column, from left to right.
    That means position (x, y) represents (var, val) in the CSP.
    The main structures are three arrays to count queens that could conflict:
        rows[i]      Number of queens in the ith row (i.e val == i)
        downs[i]     Number of queens in the \ diagonal
                     such that their (x, y) coordinates sum to i
        ups[i]       Number of queens in the / diagonal
                     such that their (x, y) coordinates have x-y+n-1 = i
    We increment/decrement these counts each time a queen is placed/moved from
    a row/diagonal. So moving is O(1), as is nconflicts.  But choosing
    a variable, and a best value for the variable, are each O(n).
    If you want, you can keep track of conflicted vars, then variable
    selection will also be O(1).
    >>> len(backtracking_search(NQueensCSP(8)))
    8
    >>> len(min_conflicts(NQueensCSP(8)))
    8
    """
    window=None
    def __init__(self, n):
        """Initialize data structures for n Queens."""
        CSP.__init__(self, range(n), UniversalDict(range(n)),
                     UniversalDict(range(n)), queen_constraint)
        update(self, rows=[0]*n, ups=[0]*(2*n - 1), downs=[0]*(2*n - 1))

    def nconflicts(self, var, val, assignment): 
        """The number of conflicts, as recorded with each assignment.
        Count conflicts in row and in up, down diagonals. If there
        is a queen there, it can't conflict with itself, so subtract 3."""
        n = len(self.vars)
        c = self.rows[val] + self.downs[var+val] + self.ups[var-val+n-1]
        if assignment.get(var, None) == val:
            c -= 3
        return c

    def assign(self, var, val, assignment):
        "Assign var, and keep track of conflicts."
        oldval = assignment.get(var, None)
        if val != oldval:
            if oldval is not None: # Remove old val if there was one
                self.record_conflict(assignment, var, oldval, -1)
            self.record_conflict(assignment, var, val, +1)
            CSP.assign(self, var, val, assignment)

    def unassign(self, var, assignment):
        "Remove var from assignment (if it is there) and track conflicts."
        if var in assignment:
            self.record_conflict(assignment, var, assignment[var], -1)
        CSP.unassign(self, var, assignment)
        
    def record_conflict(self, assignment, var, val, delta):
        "Record conflicts caused by addition or deletion of a Queen."
        n = len(self.vars)
        self.rows[val] += delta
        self.downs[var + val] += delta
        self.ups[var - val + n - 1] += delta

    def display(self, assignment):
        "Print the queens and the nconflicts values (for debugging)."
        n = len(self.vars)
        for val in range(n):
            for var in range(n):
                if assignment.get(var,'') == val: ch ='Q'
                elif (var+val) % 2 == 0: ch = '.'
                else: ch = '-'
                print ch,
            print '    ',
            for var in range(n):
                if assignment.get(var,'') == val: ch ='*'
                else: ch = ' '
                print str(self.nconflicts(var, val, assignment))+ch, 
                
                        


    def init_game(self):
        pygame.init() 
        WX = WY = 1000                 
        self.window = pygame.display.set_mode((WX, WY))
        
        if pygame.font:
                self.font = pygame.font.Font(None, 30)

        
    def Vcoords(self,Rcoords):
        return (Rcoords[0]*45+100,Rcoords[1]*45+100)
    

    def draw(self,board):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0
        
        for i in range(len(board)+1):
            if i!=len(board):
                text = self.font.render(str(i+1), 2,colors[i])
                x,y=self.Vcoords((i,-1))
                textpos = text.get_rect(centerx=x+25,centery=y+25)
                self.window.blit(text, textpos)
            #pygame.draw.line(self.window, (255,255,255),self.Vcoords((i,0)),self.Vcoords((i,len(board))))
        for j in range(len(board)+1):
            if j!=len(board):
                for q,l in board.items():
                    if l==j: break;
                        
                text = self.font.render(str(j+1), 2,colors[q])
                x,y=self.Vcoords((-1,j))
                textpos = text.get_rect(centerx=x+25,centery=y+25)
                self.window.blit(text, textpos)
            #pygame.draw.line(self.window, (255,255,255),self.Vcoords((0,j)),self.Vcoords((len(board),j)))
            
       
        for q in board:
            
            start=self.Vcoords((q,board[q]))
            pygame.draw.rect(self.window,colors[q],(start[0]+10,start[1]+10,25,25),10)
            pygame.draw.line(self.window,colors[q],self.Vcoords((0,board[q]+0.5)),self.Vcoords((len(board),board[q]+0.5)),2)
            pygame.draw.line(self.window,colors[q],self.Vcoords((q+0.5,0)),self.Vcoords((q+0.5,len(board))),2)
            #pygame.draw.line(self.window,colors[q],self.Vcoords((q-min(q,board[q]),board[q]-min(q,board[q]))),self.Vcoords((len(board)+q-max(q,board[q]),len(board)+board[q]-max(q,board[q]))),2)
            #correct this:pygame.draw.line(self.window,colors[q],self.Vcoords((,)),self.Vcoords((len(board)+q-max(q,board[q]),len(board)+board[q]-max(q,board[q]))),2)
            
        #draw it to the screen
        pygame.display.flip()
        pygame.image.save(self.window,"./%d.jpeg" % len(board))
        self.wait_game()
        
        
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

#______________________________________________________________________________
# n-Queens Problem



class KColoring(CSP):
    def __init__(self,sample=None):
        if sample:
            g=sample
        else:
            g=self.Sample_Basic()
            

        self.points=g.points
        self.links=g.links
        self.colors_list=g.colors_list
        self.colors_list.reverse()
        self.colors_definition=g.colors_definition
        self.positions=g.positions
        
        #variables
        vars=g.points
        #domains
        domains={}
        for p in self.points:
            domains[p]=self.colors_list
        #print domains
        #Nighbors
        nighbors=self.links
        #contraints
        constraint=self.constraint
        
        """Initialize data structures for n Queens."""
        CSP.__init__(self, vars,domains,nighbors,constraint)
        
        
        
        
   
    window=None #graphical window
    
    
    class Sample_Basic:
        points=[1,2,3,4,5,6,7,8,9,10]
        links={1:[2,5,6],2:[1,3,7],3:[2,8,4],4:[3,9,5],5: [4,10,1],6:[1,8,9],7:[2,9,10],8:[3,6,10],9:[4,7,6],10:[5,7,8]} 
        positions={1:(0,4),2:(4,0),3:(2,-4),4:(-2,-4),5:(-4,0) ,6:(0,2),7:(2,0),8:(1,-2),9:(-1,-2),10:(-2,0)} 
         
        colors_definition={None:(255,255,255),"red":(255,0,0),"green":(0,255,0),"blue":(0,0,255),"yellow":(255,255,0),"blue-sky":(0,255,255),"pinky":(255,0,255)}
        colors_list=["blue","red","green","yellow","pinky","blue-sky"]
        
        
    class Sample_1(Sample_Basic): #15 
        points=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
        links={1:[2,5,11,15,6],2:[1,3,11,12,7],3:[2,4,12,13,8],4:[3,5,13,14,9],5: [4,1,14,15,10],6:[8,9,1,11],7:[9,10,2,12],8:[6,10,3,13],9:[7,6,4,14],10:[7,8,5,15],11:[2,1,6],12:[2,3,7],13:[3,4,8],14:[4,5,9],15:[5,1,10]} 
        positions={1:(0,4),2:(4,0),3:(2,-4),4:(-2,-4),5:(-4,0) ,6:(0,2),7:(2,0),8:(1,-2),9:(-1,-2),10:(-2,0),11:(4,4),12:(6,-4),13:(0,-6),14:(-6,-4),15:(-4,4)} 
        initial={1:0,2:0,3:0,4:0,5:0 ,6:0,7:0,8:0,9:0,10:0,11:0,12:0,13:0,14: 0,15:0} 
        colors_definition={None:(255,255,255),"red":(255,0,0),"green":(0,255,0),"blue":(0,0,255),"yellow":(255,255,0),"blue-sky":(0,255,255),"pinky":(255,0,255)}
        colors_list=["blue","red","green","yellow","pinky","blue-sky"]
      
    class Sample_2(Sample_Basic):
        points=[1,2,3,4,5,6,7,8,9,10]
        links={1:[2,5],2:[1,3],3:[2,4],4:[3,5],5: [4,1],6:[8,9],7:[9,10],8:[6,10],9:[7,6],10:[7,8]} 
        positions={1:(0,4),2:(4,0),3:(2,-4),4:(-2,-4),5:(-4,0) ,6:(0,2),7:(2,0),8:(1,-2),9:(-1,-2),10:(-2,0)} 
        initial={1:0,2:0,3:0,4:0,5:0 ,6:0,7:0,8:0,9:0,10:0} 
        colors_definition={None:(255,255,255),"red":(255,0,0),"green":(0,255,0),"blue":(0,0,255),"yellow":(255,255,0),"blue-sky":(0,255,255),"pinky":(255,0,255)}
        colors_list=["blue","red","green","yellow","pinky","blue-sky"]
    
    class Sample_3(Sample_Basic): #15 
        points=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
        links={1:[2,5,11,15,6],2:[1,3,11,12,7],3:[2,4,12,13,8],4:[3,5,13,14,9],5: [4,1,14,15,10],6:[8,9,1,11],7:[9,10,2,7],8:[6,10,3],9:[7,6,4,14],10:[7,8,5],11:[2,1,6],12:[2,3,7],13:[3,4],14:[4,5,9],15:[5,1]} 
        positions={1:(0,4),2:(4,0),3:(2,-4),4:(-2,-4),5:(-4,0) ,6:(0,2),7:(2,0),8:(1,-2),9:(-1,-2),10:(-2,0),11:(4,4),12:(6,-4),13:(0,-6),14:(-6,-4),15:(-4,4)} 
        initial={1:0,2:0,3:0,4:0,5:0 ,6:0,7:0,8:0,9:0,10:0,11:0,12:0,13:0,14: 0,15:0} 
        colors_definition={None:(255,255,255),"red":(255,0,0),"green":(0,255,0),"blue":(0,0,255),"yellow":(255,255,0),"blue-sky":(0,255,255),"pinky":(255,0,255)}
        colors_list=["blue","red","green","yellow","pinky","blue-sky"]
        
    class Sample_4(Sample_Basic): 
        points=[1,2,3,4]
        links={1:[2,4],2:[1,3],3:[2,4],4:[3,1]} 
        positions={1:(-2,2),2:(2,2),3:(2,-2),4:(-2,-2)}  
        colors_definition={None:(255,255,255),"red":(255,0,0),"green":(0,255,0),"blue":(0,0,255),"yellow":(255,255,0),"blue-sky":(0,255,255),"pinky":(255,0,255)}
        colors_list=["blue","red","green","yellow","pinky","blue-sky"]
        

        
    def constraint(self,A, a, B, b):
        """ return false only if A,B are nighbors and have the same color"""
        X= not ((B in self.links[A] or A in self.links[B]) and a==b)
        return X
    
    def init_game(self):
        pygame.init() 
        WX = WY = 600                 
        self.window = pygame.display.set_mode((WX, WY))
        if pygame.font:
                self.font = pygame.font.Font(None, 30)

        
    def Vcoords(self,Rcoords):
        return (Rcoords[0]*45+300,600-(Rcoords[1]*45+300))
    
    def draw(self,coloring):
        if not self.window:
            self.init_game()
        radian = lambda x: (x * 3.14) / 180.0
        #####

        for (source,destinations) in self.links.items():
            source_position=self.Vcoords(self.positions[source])
            for destination in destinations:
                destination_position=self.Vcoords(self.positions[destination])
                
                pygame.draw.line(self.window, self.colors_definition[None],source_position ,destination_position)
        for p in self.points:
            pygame.draw.circle(self.window, self.colors_definition[coloring[p]],self.Vcoords(self.positions[p]),20,20)
            text = self.font.render(str(p), 2, (0, 0, 0))
            x,y=self.Vcoords(self.positions[p])
            textpos = text.get_rect(centerx=x,centery=y)
            self.window.blit(text, textpos)
        
                
        #draw it to the screen
        pygame.image.save(self.window,str(abs(hash(str(self.links))))+".jpeg")
        pygame.display.flip() 
        self.wait_game()
        
        
        
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

'''


'''
def nqueen():
    for n in range(4,11):
            NQ=NQueensCSP(n)
            #print backtracking_search(NQ)
            NQ.draw(backtracking_search(NQ))
            #NQ.display( backtracking_search(NQ))

        
def kcoloring():
    KC = KColoring();
    KC.draw(backtracking_search(KC))
    KC = KColoring(KColoring.Sample_1);
    KC.draw(backtracking_search(KC))
    KC = KColoring(KColoring.Sample_2);
    KC.draw(backtracking_search(KC))
    KC = KColoring(KColoring.Sample_3);
    KC.draw(backtracking_search(KC))
    KC = KColoring(KColoring.Sample_4);
    KC.draw(backtracking_search(KC))
    
if __name__ =="__main__":
    x=input("try : \n1.kcoloring()\n2.nqueen()\n\n Your choice?")
    if x==1:
        kcoloring()
    else :
        
        nqueen()
    
    