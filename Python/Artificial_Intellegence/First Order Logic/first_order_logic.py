# -*- Mode: Python -*-
""" 18-07-2010 - 17-08-2010 """
# experimenting with first-order logic.
# goal: a type inference engine with constraints.
# See "HM(X) Type Inference is CLP(X) Solving"
#     http://www.cs.mu.oz.au/~sulzmann/publications/hmx-clpx.pdf

# Most of this code is based on AIMA: http://aima.cs.berkeley.edu/

# status: I have SLD resolution (i.e., Prolog) working, which can
#   solve a subset of FOL.  I've also implemented a version of linear
#   resolution (which can solve KB with non-Horn clauses), but since I
#   don't *need* it (and it's *hard*), I will just move on...
# next step: add support for constraints.

# The input syntax (for the 'tell()' method) is a lisp/prefix expression.
#   "A => B|C" becomes (=> A (or B C))
# See the tests for samples.
# FOL Propositionalization, unification and lifting, skolemezation, forward and backward chaining 

from pprint import pprint as pp
import sys,re

is_a = isinstance

# simple lisp reader for expressions
class lisp_reader:

    def __init__ (self, file):
        self.file = file
        self.char = None
        self.line = 1

    def peek (self):
        if self.char is None:
            self.char = self.file.read (1)
        return self.char

    def next (self):
        result, self.char = self.char, self.file.read (1)
        if result == '\n':
            self.line += 1
        return result

    def skip_whitespace (self):
        while 1:
            ch = self.peek()
            if not ch:
                break
            elif ch not in ' \t\r\n':
                if ch == ';':
                    while self.next() not in '\r\n':
                        pass
                else:
                    break
            else:
                self.next()

    def read (self):
        self.skip_whitespace()
        ch = self.peek()
        if ch == '':
            raise EOFError, "Unexpected end of file"
        elif ch == '(':
            return self.read_list()
        elif ch in '0123456789':
            a = self.read_atom()
            all_digits = 1
            for ch in a:
                if ch not in '0123456789':
                    all_digits = 0
                    break
            if all_digits:
                return int (a)
            else:
                return a
        else:
            return self.read_atom()

    def read_atom (self):
        # read at least one character
        line = self.line
        result = self.next()
        while 1:
            ch = self.peek()
            if ch in ' \t\r\n' or ch in '()':
                return result
            else:
                result = result + self.next()

    def read_list (self):
        result = []
        # throw away the paren
        paren = self.next()
        while 1:
            self.skip_whitespace()
            p = self.peek()
            if p == ')':
                # throw away the paren
                ch = self.next()
                return tuple (result)
            else:
                exp = self.read()
                result.append (exp)

def read_string (s):
    import cStringIO
    r = lisp_reader (cStringIO.StringIO (s))
    return r.read()

def map_args (op, fun, exp):
    return (op,) + tuple ([fun(x) for x in exp[1:]])

def negate (e):
    return ('not', e)

class counter:
    def __init__ (self, init=0):
        self.val = init
    def next (self):
        result, self.val = self.val, self.val + 1
        return result

class UnboundVariableError (Exception):
    pass

# I think we want these globally unique
alpha_counter = counter()
skolem_counter = counter()



#############################################################################
#############################################################################

def to_cnf (e):
    print e

    def unimply (e):
        if is_a (e, tuple):
            op = e[0]
            if op == '=>':
                _, ant, con = e
                return ('or', unimply (('not', ant)), unimply (con))
            if op == '<=>':
                _, ant, con = e                
                return ('and', unimply (('=>', ant, con)), unimply (('=>', con, ant)))
            else:
                return map_args (op, unimply, e)
        else:
            return e

    def move_not_inward (e):
       
        if is_a (e, tuple):
            op = e[0]
            if op == 'not':
                _, e = e
                if is_a (e, tuple):
                    op = e[0]
                    if op == 'not':
                        _, e = e
                        return move_not_inward (e)
                    elif op == 'or':
                        _, a, b = e
                        return ('and', move_not_inward (('not', a)), move_not_inward (('not', b)))
                    elif op == 'and':
                        _, a, b = e
                        return ('or', move_not_inward (('not', a)), move_not_inward (('not', b)))
                    elif op == 'forall':
                        op, var, e = e
                        return ('exists', var, move_not_inward (('not', e)))
                    elif op == 'exists':
                        op, var, e = e
                        return ('forall', var, move_not_inward (('not', e)))
                    else:
                        # XXX ground term - we need to verify no more ops below here!
                        return ('not', map_args (op, move_not_inward, e))
                else:
                    return ('not', e)
            else:
                return map_args (op, move_not_inward, e)
        else:
            return e

    def lookup (name, lenv):
        while lenv is not None:
            (var, val), lenv = lenv
            if name == var:
                return val
        raise UnboundVariableError (name)

    def standardize_apart (e, lenv=None):
        # alpha renaming
        if is_a (e, tuple):
            op = e[0]
            if op in ('forall', 'exists'):
                _, var, e = e
                new = '%s_%d' % (var, alpha_counter.next())
                lenv = ((var, new), lenv)
                return (op, new, standardize_apart (e, lenv))
            else:
                return map_args (op, lambda x: standardize_apart (x, lenv), e)
        elif is_a (e, str) and e[0] == e[0].lower():
            # symbols starting with lower-case letter are variables
            # XXX think about doing this in the parser and making a class for vars
            return lookup (e, lenv)
        else:
            return e

    def skolemize (e, lenv=None):
        if is_a (e, tuple):
            op = e[0]
            if op == 'forall':
                # another universally-quantified set of vars, add them
                _, var, e = e
                lenv = ((var, ('all', var)), lenv)
                return (op, var, skolemize (e, lenv))
            elif op == 'exists':
                # collect all universally bound
                univ_bound = []
                search = lenv
                while search is not None:
                    (var, val), search = search
                    if val[0] == 'all':
                        univ_bound.append (var)
                # conjure up a new skolem name
                fun = 'SK_%d' % (skolem_counter.next(),)
                if len(univ_bound):
                    # make it a function of the univ bound vars
                    fun = (fun,) + tuple (univ_bound)
                else:
                    # it's just a new constant
                    pass
                _, var, e = e
                # bind it into the environment
                lenv = ((var, ('exists', fun)), lenv)
                # and continue
                return skolemize (e, lenv)
            else:
                return map_args (op, lambda x: skolemize (x, lenv), e)
        elif is_a (e, str) and e[0] == e[0].lower():
            # symbols starting with lower-case letter are variables
            # XXX think about doing this in the parser and making a class for vars
            kind, val = lookup (e, lenv)
            return val
        else:
            return e

    def drop_quantifiers (e):
        # all quantifiers must be universal now
        if is_a (e, tuple):
            op = e[0]
            if op == 'forall':
                return drop_quantifiers (e[2])
            else:
                return map_args (op, drop_quantifiers, e)
        else:
            return e

    def distribute_and_over_or (e):
        def F (e):
            # let's try it simply first
            if is_op (e, 'or'):
                _, e0, e1 = e
                e0, e1 = F(e0), F(e1)
                if is_op (e0, 'and'):
                    # ((f0 & f1) | e1) => (f0|e1) & (f1|e1)
                    _, f0, f1 = e0
                    return ('and', F (('or', f0, e1)), F (('or', f1, e1)))
                elif is_op (e1, 'and'):
                    # (e0 | (f0 & f1)) => (f0|e0) & (f1|e0)
                    _, f0, f1 = e1
                    return ('and', F (('or', f0, e0)), F (('or', f1, e0)))
                else:
                    return ('or', e0, e1)
            elif is_a (e, tuple):
                return map_args (e[0], F, e)
            else:
                return e
        return F (e)

    def flatten (e):
        if is_a (e, tuple):
            if e[0] in ('and', 'or'):
                op, e0, e1 = e
                e0, e1 = flatten (e0), flatten (e1)
                if is_op (e0, op):
                    r = e0[1:]
                else:
                    r = (e0,)
                if is_op (e1, op):
                    r += e1[1:]
                else:
                    r += (e1,)
                return (op,) + r
            else:
                return map_args (e[0], flatten, e)
        else:
            return e

    e = unimply (e)
    e = move_not_inward (e)
    # this is done in the solver
    #e = standardize_apart (e)
    e = skolemize (e)
    e = drop_quantifiers (e)
    e = distribute_and_over_or (e)
    e = flatten (e)

    return e

def is_op (e, op):
    return is_a (e, tuple) and e[0] == op

def parse (s):
    return read_string (s)

def unparse (e):
    if is_a (e, tuple):
        return ('(%s ' % e[0]) + ' '.join ([unparse(x) for x in e[1:]]) + ')'
    else:
        return '%s' % (e,)

def simplify (e):
    # 1) make and & or binary operators
    # 2) make quantifiers bind only one variable
    if is_a (e, tuple):
        op = e[0]
        if op in ('and', 'or'):
            if len (e) > 3:
                return (op, e[1], simplify ((op,) + e[2:]))
            else:
                return e
        elif op in ('forall', 'exists'):
            op, vars, e = e
            if len(vars) > 1:
                return (op, vars[0], simplify ((op, vars[1:], e)))
            else:
                return (op, vars[0], simplify (e))
        else:
            return map_args (op, simplify, e)
    else:
        return e

def infix (e):
    if is_a (e, set):
        # special case to handle disjunct_sets
        return infix (('or',) + tuple (e))
    elif is_a (e, tuple):
        op = e[0]
        if op in ('and', 'or'):
            op = ' %s ' % ({'and':'&','or':'|'}[op],)
            return '(' + op.join ([infix (x) for x in e[1:]]) + ')'
        elif op == 'not':
            return '~%s' % (infix (e[1]),)
        else:
            return '%s(%s)' % (op, ', '.join ([infix(x) for x in e[1:]]))
    else:
        return '%s' % (e,)

def conjuncts (e):
    if is_op (e, 'and'):
        return e[1:]
    else:
        return [e]

def disjuncts (e):
    if is_op (e, 'or'):
        return e[1:]
    else:
        return [e]

def disjunct_set (e):
    if is_op (e, 'or'):
        return set (e[1:])
    else:
        return {e}

def size (x):
    if is_a (x, tuple):
        r = 0
        for y in x:
            r += size (y)
        return r
    else:
        return 1

class clause:
    def __init__ (self, lits):
        self.lits = set(lits)
        self.predicates = {}
        for lit in lits:
            pred = get_predicate (lit)
            if self.predicates.has_key (pred):
                self.predicates[pred].append (lit)
            else:
                self.predicates[pred] = [lit]
        self.size = self.compute_size()

    def __len__ (self):
        return len (self.lits)

    def compute_size (self):
        r = 0
        for l in self.lits:
            r += size (l)
        return r

    def __cmp__ (self, other):
        assert (is_a (other, clause))
        #diff = self.lits.symmetric_difference (other.lits)
        if self.lits == other.lits:
            return 0
        else:
            return -1

    def find_complements (self, other):
        # return all possible pairs of complements
        assert (is_a (other, clause))
        pla = self.predicates
        plb = other.predicates
        if len(pla) > len (plb):
            pla, plb = plb, pla
        r = []
        used = set()
        for key in pla.iterkeys():
            if plb.has_key (key):
                for lita in pla[key]:
                    for litb in plb[key]:
                        if is_not (lita) != is_not (litb):
                            if lita not in used and litb not in used:
                                r.append ((lita, litb))
                                used.add (lita)
                                used.add (litb)
        return r

    def resolve (self, other):
        complements = self.find_complements (other)
        complements.reverse()
        if len(complements):
            # second, try to unify each of the pairs
            eliminated = set()
            for x0, y0 in complements:
                if is_not (x0):
                    x1, y1 = x0[1], y0
                else:
                    x1, y1 = x0, y0[1]
                try:
                    # XXX fixme - don't pass subst down
                    subst = {}
                    unify (x1, y1, subst)
                except UnifyError:
                    pass
                else:
                    print '**eliminated', infix(x0), infix(y0)
                    eliminated.add (x0)
                    eliminated.add (y0)
            if len (eliminated):
                return subst, clause (self.lits.union (other.lits) - eliminated)
            else:
                return False
        else:
            return False

    def apply_subst (self, subst):
        return clause (set ([apply_subst (x, subst) for x in self.lits]))

    def standardize_apart (self, suffix):
        map = {}
        def F (e):
            if is_a (e, tuple):
                return map_args (e[0], F, e)
            elif is_var (e):
                if map.has_key (e):
                    return map[e]
                else:
                    map[e] = add_suffix (e, suffix)
                    return map[e]
            else:
                return e
        return clause (set ([F(x) for x in self.lits]))

    def __repr__ (self):
        return infix (('or',) + tuple (self.lits))

def add_suffix (var, suffix):
    # add a suffix, replacing one if it's already there
    p = var.rfind ('_')
    if p == -1:
        return '%s_%s' % (var, suffix)
    else:
        return '%s_%s' % (var[:p], suffix)

class knowledge_base:

    def __init__ (self):
        self.clauses = []

    def tell (self, s):
        # store the clauses as sets of literals
        for c in conjuncts (to_cnf (simplify (parse (s)))):
            self.clauses.append (clause (disjunct_set (c)))

    def dump (self):
        print "clauses",self.clauses
        print 'KB {'
        for c in self.clauses:
            print '  %s,' % (infix (c),)
        print '}'

def is_var (e):
    return is_a (e, str) and len(e) and e[0] == e[0].lower()

def is_const (e):
    return is_a (e, str) and len(e) and e[0] == e[0].upper()

def is_predicate (e):
    return is_a (e, tuple) and is_const (e[0])

# base types that allow simple comparison.
# [we want to avoid using 'x == y', which will do deep comparisons]
simple = (int, str)

class UnifyError (Exception):
    pass

def unify (x, y, subst={}):
    if is_a (x, int) and is_a (y, int) and x == y:
        return subst
    elif is_const (x) and is_const (y) and x == y:
        return subst
    elif is_var (x):
        return unify_var (x, y, subst)
    elif is_var (y):
        return unify_var (y, x, subst)
    elif is_predicate (x) and is_predicate (y):
        if x[0] != y[0]:
            raise UnifyError (x, y, subst)
        else:
            return unify_sequence (x[1:], y[1:], subst)
    elif is_a (x, list) and is_a (y, list):
        return unify_sequence (x, y,subst)
    else:
        raise UnifyError (x, y, subst)

def unify_var (v, x, subst):
    if subst.has_key (v):
        return unify (subst[v], x, subst)
    else:
        occurs_check (v, x)
        subst[v] = x
        return subst

def unify_sequence (x, y, subst):
    if len(x) != len(y):
        raise UnifyError (x, y, subst)
    else:
        for i in range (len (x)):
            subst = unify (x[i], y[i], subst)
        return subst

def occurs_check (v, x):
    if is_var (x):
        if v == x:
            raise UnifyError (v, x, "occurs check")
    elif is_a (x, tuple):
        for y in x[1:]:
            occurs_check (v, y)
    else:
        pass

def apply_subst (x, subst):
    if is_var (x):
        while subst.has_key (x):
            x = subst[x]
        return x
    elif is_a (x, tuple):
        return (x[0],) + tuple ([apply_subst(y, subst) for y in x[1:]])
    else:
        return x

def flatten_subst (substs):
    if substs is not None:
        subst, substs = substs

def U (x, y, subst):
    print '    unify', infix(x), infix(y)
    r = unify (x, y, subst)
    print '    =>', r
    return r

def is_not (e):
    return is_a (e, tuple) and e[0] == 'not'

def get_predicate (e):
    assert (is_a (e, tuple))
    if e[0] == 'not':
        e = e[1]
    assert is_a (e, tuple)
    assert (e[0][0] == e[0][0].upper())
    return e[0]

def get_variables (e):
    if is_a (e, tuple) and e[0] in ('forall', 'exists'):
        return e[1]
    else:
        return ()

class Solved (Exception):
    pass

def print_answer (vars, vals):
    if vars:
        print 'answer:'
        for i in range (len (vars)):
            print '%s=%s' % (vars[i], infix (vals[i]))
        raw_input()
    else:
        raise Solved

# --- resolution ---
def linear_resolution (kb, question, success=print_answer, randomize=False, negate_query=True):
    clauses = kb.clauses
    # negate the goal
    question = parse (question)
    # pull out any variables the user is looking for
    vars = get_variables (question)
    goals = conjuncts (to_cnf (simplify (question)))
    # XXX until I understand how to handle it...
    assert (len (goals) == 1)
    if negate_query:
        goal = clause ([negate (goals[0])])
    else:
        goal = clause (disjunct_set (goals[0]))
    print 'goal:', goal
    
    def search (clauses, goal, substs, depth=0):

        def I (s):
            pass
            #print '%s%s' % (depth * '  ', s)

        I ('search: [%d] %r' % (goal.size, goal,))
        if randomize:
            import random
            random.shuffle (clauses)
        else:
            # sort by size (i.e., unit preference)
            clauses.sort (lambda a,b: cmp (a.size, b.size))
            
        for c in clauses:
            I ('  trying: %r  %r' % (goal, c))
            # I don't like this, but it seems to be the only
            #   way to get a composable substitution.  Maybe
            #   I can build it into resolve()?
            c = c.standardize_apart (str (depth+1))
            probe = c.resolve (goal) # goal.resolve (c)
            if probe is not False:
                subst, resolvent = probe
                I ('  resolvent: %r' % (resolvent,))
                # did we get the empty clause?
                if len(resolvent) == 0:
                    # return the solution
                    I (' * subst : %r' % (subst,))
                    success (vars, [apply_subst (x, subst) for x in vars])
                else:
                    # apply <subst> to the resolvent
                    if subst:
                        I (' * subst : %r' % (subst,))
                        I (' * before: %r' % (resolvent,))
                        resolvent = resolvent.apply_subst (subst)
                        I (' * after : %r' % (resolvent,))
                        if resolvent in clauses:
                            # a loop, get out
                            I ('LOOP, BACKTRACKING...')
                            continue
                    # make the resolvent the new goal
                    # add the previous resolvent to the set of clauses (makes this 'linear resolution')
                    raw_input()
                    search (clauses + [goal], resolvent, (subst, substs), depth+1)
                    # do *not* add it (makes this 'input resolution')
                    #search (clauses, resolvent, (subst, substs), depth+1)
                    I ('BACKTRACKING...')

    try:
        search (clauses, goal, None)
    except Solved:
        pass
    else:
        print 'NO'

class horn_knowledge_base:

    def __init__ (self):
        self.rules = {}

    def tell (self, s):
        for c in conjuncts (to_cnf (simplify (parse (s)))):
            lits = disjuncts (c)
            body = []
            head = None
            for lit in lits:
                if is_not (lit):
                    body.append (lit[1])
                elif head is not None:
                    raise ValueError ("non-Horn clause: %r" % (s,))
                else:
                    head = lit
            head_pred = get_predicate (head)
            # store each rule as follows:
            # rules[PRED] = [[head0, body0_0, body0_1, ...], [head1, body1_0, body_1_1, ...]]
            if self.rules.has_key (head_pred):
                self.rules[head_pred].append ([head] + body)
            else:
                self.rules[head_pred] = [[head] + body]

    def dump (self):
        print 'HornKB {'
        for pred in self.rules.keys():
            for rule in self.rules[pred]:
                head, body = rule[0], rule[1:]
                if len(body):
                    print '  %s :- %s.' % (infix(head), ', '.join ([infix(x) for x in body]))
                else:
                    print '  %s.' % (infix(head),)
        print '}'

    def apply_subst (self, exp, subst):
        def F (exp):
            if is_var (exp) and subst.has_key (exp):
                return F (subst[exp])
            elif is_a (exp, tuple):
                return map_args (exp[0], F, exp)
            else:
                return exp
        return F (exp)

    def standardize_apart (self, e, suffix):
        def F (e):
            if is_a (e, tuple):
                return map_args (e[0], F, e)
            elif is_var (e):
                return add_suffix (e, suffix)
            else:
                return e
        return F (e)

    def sld_resolution (self, query, success=print_answer):
        # negate the goal
        query = parse (query)
        # pull out any variables the user is looking for
        vars = get_variables (query)

        goals = conjuncts (to_cnf (simplify (query)))

        
        def search (goals, vals, depth):
            goal = goals[0]
            goal_pred = get_predicate (goal)
            #print '%sgoal:%s' % ('  ' * depth, infix (goal))
            for rule in self.rules[goal_pred]:

                # can we unify this head with our goal?
                subst = {}
                #print '%stry %s :- %s' % ('  ' * depth, infix(head), ', '.join ([infix(x) for x in body]))
                rule = [self.standardize_apart (x, str(depth)) for x in rule]
                head = rule[0]
                body = rule[1:]
                
                try:
                    unify (head, goal, subst)
                except UnifyError:
                    pass
                else:
                    goals = body + goals[1:]

                    #print '%s[%d] goals: %s' % ('  ' * depth, len(goals), [infix(x) for x in goals])
                    #print '%ssubst:%r' % ('  ' * depth, subst)
                    if len(goals) == 0:
                        success (vars, [self.apply_subst (v, subst) for v in vals])
                    else:
                        search (
                            [self.apply_subst (x, subst) for x in goals],
                            [self.apply_subst (v, subst) for v in vals],
                            depth + 1
                            )
        try:
            search (goals, vars, 0)
        except Solved:
            print 'YES'
        else:
            print 'NO'

    def ask (self, query):
        self.sld_resolution (query)
        
        
##############################################
## Added By Assem                           ##        
############################################## 
def is_renaming(s1,s2):
        """
        s1 is a renaming of s2 if they are identical except for the names of variables
        """
        decision=True
        if len(s1)!=len(s2):
            decision=False
        else:
            for i in range(len(s1)):
                if is_var(s1[i]) and is_var(s2[i]) :
                    pass
                elif is_const(s1[i]) and is_const(s2[i]) and s1[i]==s2[i]:
                    pass
                elif is_predicate(s1[i]) and is_predicate(s2[i]):
                    if not is_renaming(s1[i],s2[i]):
                        decision=False
                        break;
                else:
                    decision=False
                    break;
        return decision

def is_implication(x):
    return True if is_a(x,list) and len(x)>1 else False

def is_fact(x):
    return True if ((is_a(x,list) and len(x)==1)) or is_a(x,tuple) else False



def possible_substs(KB,P):
    """ 
        find each substitution S such Subst(S,p1,p2...)=Subst(S,p_1,p_2...) for some p_1,p_2 in KB
        @param KB: the knowledge base
        @param p: 
        @return : list of all possible substitution
                
    """
    substs=[{}]
    finalset={}
    for p in P:
        tempset={}
        for rules in KB.rules.values():
            for r in rules:
                if is_fact(r):
                    subst={}
                    s=r[0]
                    
                    if s[0]==p[0]:
                        try:   
                            unify(p, s, subst)
                        except:
                            pass
                        else:
                            for k,v in subst.items():
                                if tempset.has_key(k):
                                    tempset[k].add(v)
                                else:
                                    tempset[k]= {v}
                                


        for k,v in tempset.items():
            if finalset.has_key(k):
                finalset[k]&=v
            else:
                finalset[k]=v
            

    for k,vset in finalset.items():
        for v in vset:
            temp=[]
            for s in substs:
                D= {k: v}
                D.update(s)
                temp.append(D)
            substs=temp
            
    
    return substs
   
def exist_in_list(q,lst):
    """   """
    j=0
    exist=False
    while j<len(lst) and not exist:
        r=lst[j]
        j+=1
        if is_fact(r):
            if is_renaming(r,q):
                exist=True

    return exist
                    
       
   
def exist_in_kb(q,KB):
        """ test if a sentence is already exist in the Knowledge base such if its renamed """
        exist,i=False,0
        Rules=KB.rules.values()
        while i<len(Rules) and not exist:
            for lst in  Rules[i]:
                exist|=exist_in_list(q,lst)
            i+=1
        
        return exist
    
   
    
def FOL_FC_ASK(KB,alpha):
    """
    Forward chaining 
    
    @param KB: the knowledge base
    @param alpha: the query,an atomic sentence
    
    @return: a substitution or false
   
    """
    new=True
    phi={}; 
    query=parse(alpha) if is_a(alpha,str) else alpha
    depth=0
    cpt=0
    OK=False
    while new  :
        new=[]
        cpt+=1
        for rules in KB.rules.values() if not OK else [] :
            for r in rules if not OK else []:
                if is_implication(r):
                    rule = [KB.standardize_apart (x, str(depth)) for x in r]
                    q = rule[0]
                    p = rule[1:]
                    for subst in possible_substs(KB,p) if not OK else []:
                            q_=KB.apply_subst(q,subst)
                            print q,"||=========",subst,"========>>",q_
                            if not exist_in_kb(q_,KB) and not exist_in_list(q_,new):
                                new.append(q_)
                                print q_,query
                                if q_==query:
                                    OK=True
                                else:
                                    try:
                                        
                                        unify(q_,query,phi)#?
                                    except:
                                        pass
                                    else:
                                        OK=True
                                        

        for s in new:
            KB.rules[s[0]].append([s])
            
        #depth+=1

    print "\n\nFOL-Forward Chaining :\n The system is %s satisfied/PHI=%s " % ("" if OK else "not",str(lastphi))
    KB.dump()
    return OK if phi else phi





def FOL_BC_ASK(KB,goals,subst={},depth=0):
    """
    Backward chaining 
    
    @param KB: the knowledge base
    @param goals: a list of conjuncts forming a query
    @param subst: the current substitution
    
  
    @return: a  set of substitutions

    """
    OK=False
    answers={}
    if not goals:
        answers.update(subst)
        OK=True
    else:
        q_=apply_subst(goals[0], subst)
        for rules in KB.rules.values():
            for r in rules:
                    rule = [KB.standardize_apart (x, str(depth)) for x in r]
                    q = rule[0]
                    p = rule[1:]
                    try:
                            subst_={}
                            unify(q, q_, subst_)
                    except:
                            pass
                    else:
                            new_subst={};
                            new_subst.update(subst);
                            new_subst.update(subst_)
                            new_goals=[] 
                            p_=map(lambda c:c,p)
                            new_goals.extend(p_);
                            new_goals.extend(goals[1:])
                            
                            
                            ## the printing is little different from what happens in the algorithm
                            ## the algorithm use composition of substitutions whose effect is identical to
                            ## the effect of applying each substituation in turn 
                            
                            if not is_fact(r):
                                depth+=1
                                print "\n*******Substitution %d **********\ngoals = " % depth ,map(lambda c:apply_subst(c, subst),goals)
                                print q,"\t<=====",subst_,"======>\t",q_
                                print "new_goals",map(lambda c:apply_subst(c, new_subst),new_goals)
                            else:
                                print "\n*********Satisfaction************\n",q



                            OK,new_answers=FOL_BC_ASK(KB,new_goals,new_subst,depth).values()
                            answers.update(new_answers)

    return {"OK":OK,"answers":answers}
 
 


  
def lightest(sos):
    min=99999
    
    index=None
    for i in range(len(sos)):
        size=sos[i].size
        if size<min:
            min = size
            index=i
   
    return index
  



def Otter(sos,usable):
    """
    @param sos: a set of support - clauses defining the problem
    @param usable: background knowledge potentially relevant to the problem
    """
    CPT=0
    refutation=False
    while sos and not refutation:
        i=lightest(sos)
        clause=sos[i]
        CPT+=1
        print 
        print CPT,"choosed",clause
        sos.pop(i)
        usable.append(clause)
        refutation=Process(Infer(clause,usable),sos)
        
    return refutation,CPT



def Infer(clause,usable):
    """
    @param clause:
    @param usable:
    
    @return : the resulting clauses 
    """

    res=[]
    for cl in  [cl for cl in map(lambda x:clause.resolve(x),usable) if (cl!=False) ]:
        new=cl[1].apply_subst(cl[0])
        if not exist_in_list(new,usable):
            res.append(new)
        else:print "++"

    return tuple(res)





def Merge_identical_literals(clause):
    """ the literals is implemented as a Set and it automatically merges identical members"""
    return clause


def Process(clauses, sos ):
    refutation=False
    for clause in clauses:
        clause=simplify(clause)
        Merge_identical_literals(clause)
        sos.insert(0,clause)
        nb=len(clause)
        if nb==0:
            refutation=True
        elif nb==1:
            #refutation unit?!!
            pass
                
    return refutation

def thm_provers(goal,kb):
    """
    
    """
    sos=[clause (disjunct_set(c)) for c in conjuncts (to_cnf (simplify (parse ("(not "+goal+")"))))]
    usable=kb.clauses
    
    OK,CPT=Otter(sos, usable)
    print "\n\nTheorem Provers -Otter algorithm :\n The system is %sresolved/steps=%d " % ("" if OK else "not ",CPT)
    
    
    return OK

    

# NOTE: when translating Prolog code into FOL, it's very important to remember
#   that the implication symbol is *reversed* in Prolog:
#
#  A :- B,C  ==  B&C->A == ~B|~C|A (i.e., each rule is a definite clause)
#
#   Another gotcha: in FOL, it's common for constants/predicates to start with
#   an upper-case letter, and variables to start with a lower-case letter.  This
#   too is reversed in Prolog!
#
#  Sample conversion: "p(Z) :- q(Z),m(Z)"
#    becomes "(forall (z) (=> (and (Q z) (M z)) (P z)))"
#


class Test:
    """
    the global class of all  tests

    """
       
    @staticmethod
    def test2_to_cnf():
        # test to_cnf
        import sys
        pp = lambda x: sys.stdout.write ('%s\n' % (infix(x),))
        pp (to_cnf (parse ('(=> X (not Y))')))
        pp (to_cnf (parse ('(=> (not X) Y)')))
        pp (to_cnf (parse ('(not (not (not (not X))))')))
        pp (to_cnf (parse ('(not (or X (and Y Z)))')))
        pp (to_cnf (parse ('(not (or X (and Y (=> A B))))')))
        pp (to_cnf (parse ('(not (or (not (or A (not B))) (not (not C))))')))
        pp (to_cnf (parse ('(or (forall x (P x)) (exists x (Q x)))')))
        pp (to_cnf (parse ('(exists x (forall x (or (P x) (Q x))))')))
        pp (to_cnf (parse ('(forall x (or (exists y (and (Animal y) (not (Loves x y)))) (exists z (Loves z x))))')))
        pp (to_cnf (parse ('(or (and A B) C)')))
        pp (to_cnf (parse ('(or (and A B) (and C D))')))

    @staticmethod
    def test3_sld_resolution():
        kb = horn_knowledge_base()
        kb.tell ('(forall (x y z) (=> (and (American x) (Weapon y) (Sells x y z) (Hostile z)) (Criminal x)))')
        kb.tell ('(American West)')
        kb.tell ('(exists (x) (and (Owns Nono x) (Missile x)))')
        kb.tell ('(forall (x) (=> (Missile x) (Weapon x)))')
        kb.tell ('(forall (x) (=> (and (Missile x) (Owns Nono x)) (Sells West x Nono)))')
        kb.tell ('(forall (x) (=> (Enemy x America) (Hostile x)))')
        kb.tell ('(Enemy Nono America)')
        kb.dump()
        print "rules>>>>>>>>>>>>>>>>>>", kb.rules
        kb.sld_resolution ('(Criminal West)')
        #linear_resolution (kb, '(Criminal West)')
        return kb
    @staticmethod
    def test4_linear_resolution():
        kb = knowledge_base()
        kb.tell ('(forall (x) (Add x 0 x))')
        kb.tell ('(forall (x y z) (=> (Add x y z) (Add x (S y) (S z))))')
        kb.dump()
        #linear_resolution (kb, '(forall (v) (Add (S 0) v (S (S 0))))')
        #linear_resolution (kb, '(forall (v) (Add (S (S 0)) (S (S 0)) v))')
        linear_resolution (kb, '(forall (u v) (Add u v (S (S (S 0)))))')

    @staticmethod
    def test5_linear_resolution():
        # This one can't be done with SLD since the first clause is not a Horn clause.
        kb = knowledge_base()
        kb.tell ('(forall (x) (=> (forall (y) (=> (Animal y) (Loves x y))) (exists (y) (Loves y x))))')
        kb.tell ('(forall (x) (=> (exists (y) (and (Animal y) (Kills x y))) (forall (z) (not (Loves z x)))))')
        kb.tell ('(forall (x) (=> (Animal x) (Loves Jack x)))')
        kb.tell ('(or (Kills Jack Tuna) (Kills Curiosity Tuna))')
        kb.tell ('(Cat Tuna)')
        kb.tell ('(forall (x) (=> (Cat x) (Animal x)))')
        kb.dump()
        linear_resolution (kb, '(Kills Curiosity Tuna)')

# from http://www.cs.miami.edu/~geoff/Courses/CSC648-07F/Content/LinearResolution.shtml

# S6 = { p(Z) | q(Z),
#       ~p(X) | t(X),
#       ~p(X) | s(X),
#       ~t(b) | p(b),
#       ~t(b) | s(b),
#       ~s(b) | m(W),
#       ~s(b) | ~m(a),
#       ~q(a),
#       ~q(T) | s(T) }
    
    @staticmethod
    def test6_linear_resolution():
        kb = knowledge_base()
        kb.tell ('(forall (x) (or (not (P x)) (T x)))')
        kb.tell ('(forall (x) (or (not (P x)) (S x)))')
        kb.tell ('(or (not (T B)) (P B))')
        kb.tell ('(or (not (T B)) (S B))')
        kb.tell ('(forall (w) (or (not (S B)) (M w)))')
        kb.tell ('(or (not (S B)) (not (M A)))')
        kb.tell ('(not (Q A))')
        kb.tell ('(forall (t) (or (not (Q t)) (S t)))')
        kb.dump()
        # 'top clause' is the query?
        linear_resolution (kb, '(forall (z) (or (P z) (Q z)))', negate_query=False)

    @staticmethod
    def test7_linear_resolution():
        kb = knowledge_base()
        kb.tell ('(forall (a l1 l2 l3) (=> (Append l1 l2 l3) (Append (Cons a l1) l2 (Cons a l3))))')
        kb.tell ('(forall (l1 l2) (Append Nil l1 l1))')
        #linear_resolution (kb, '(forall (z) (Append (Cons A (Cons B Nil)) (Cons B (Cons C Nil)) z))')
        linear_resolution (kb, '(forall (u v) (Append u v (Cons A (Cons B (Cons C (Cons D Nil))))))')

    @staticmethod
    def test8_towers_of_hanoi():
        # towers of hanoi
        kb = horn_knowledge_base()
        kb.tell ('(forall (n output) (=> (Move A B C n output) (Hanoi n output)))')
        kb.tell (
            '(forall (a b c m output out1 out2)'
            '  (=> (and (Move a c b m out1) (Move c b a m out2) (Append out1 (Cons (To a b) out2) output))'
            '      (Move a b c (Succ m) output)))'
            )
        kb.tell ('(forall (l1) (Append Nil l1 l1))')
        kb.tell ('(forall (a l1 l2 l3) (=> (Append l1 l2 l3) (Append (Cons a l1) l2 (Cons a l3))))')
        kb.tell ('(forall (a b c) (Move a b c 0 Nil))')
        kb.dump()
        kb.ask ('(forall (z) (Hanoi (Succ (Succ (Succ 0))) z))')
    
    @staticmethod
    def test9_ask():
        kb = horn_knowledge_base()
        kb.tell ('(French Jean)')
        kb.tell ('(French Jacques)')
        kb.tell ('(British Peter)')
        kb.tell ('(forall (x y) (=> (and (French x) (Wine y)) (Likewine x y)))')
        kb.tell ('(forall (x) (=> (British x) (Likewine x Bordeaux)))')
        kb.tell ('(Wine Burgundy)')
        kb.tell ('(Wine Bordeaux)')
        kb.ask ('(forall (u v) (Likewine u v))')

    # from wikipedia
    @staticmethod
    def test11_linear_resolution():
        kb = knowledge_base()
        kb.tell ('(forall (x y z) (=> (and (Parent_Child z x) (Parent_Child z y)) (Sibling x y)))')
        kb.tell ('(forall (x y) (=> (Father_Child x y) (Parent_Child x y)))')
        kb.tell ('(forall (x y) (=> (Mother_Child x y) (Parent_Child x y)))')
        kb.tell ('(Mother_Child Trude Sally)')
        kb.tell ('(Father_Child Tom Sally)')
        kb.tell ('(Father_Child Tom Erica)')
        kb.tell ('(Father_Child Mike Tom)')
        #linear_resolution (kb, '(Sibling Sally Erica)')
        linear_resolution (kb, '(forall (f c) (Father_Child f c))')
    
    @staticmethod
    def test12_ask():
        kb = horn_knowledge_base()
        kb.tell ('(forall (a l1 l2 l3) (=> (Append l1 l2 l3) (Append (Cons a l1) l2 (Cons a l3))))')
        kb.tell ('(forall (l1 l2) (Append Nil l1 l1))')
        #linear_resolution (kb, '(forall (z) (Append (Cons A (Cons B Nil)) (Cons B (Cons C Nil)) z))')
        kb.ask ('(forall (u v) (Append u v (Cons A (Cons B (Cons C (Cons D Nil))))))')
        #kb.sld_resolution ('(forall (u v) (Append u v (Cons A Nil)))')

    @staticmethod
    def test13_ask():
        # PLAI chapter 33 - Type Inference
        kb = horn_knowledge_base()
        kb.tell ('(forall (x) (Type x NumConst Num))')
        kb.tell ('(forall (x) (Type x BoolConst Bool))')
        kb.tell (
            '(forall (tenv tau test then else)'
            '        (=> (and (Type tenv test Bool) (Type tenv then tau) (Type tenv else tau))'
            '            (Type tenv (If test then else) tau)))'
            )
        # rules for variable binding
        kb.tell ('(forall (v t x) (Type (Cons (Bind v t) x) (Var v) t))')
        kb.tell ('(forall (v t x y tenv_rest) (=> (Type tenv_rest (Var v) t) (Type (Cons (Bind x y) tenv_rest) (Var v) t)))')
        # rule for functions
        kb.tell (
            '(forall (tenv var body t1 t2)'
            '   (=> (Type (Cons (Bind var t1) tenv) body t2)'
            '       (Type tenv (Fun var body) (Arrow t1 t2))))'
            )
        # rule for application
        kb.tell (
            '(forall (tenv fun arg t1 t2)'
            '   (=> (and (Type tenv fun (Arrow t1 t2)) (Type tenv arg t1))'
            '       (Type tenv (App fun arg) t2)))'
            )
        kb.dump()
        if False:
            kb.ask ('(Type Nil BoolConst Bool)')
            kb.ask ('(Type Nil (If BoolConst NumConst NumConst) Num)')
            kb.ask ('(Type Nil (If BoolConst NumConst NumConst) Num)')
            kb.ask ('(Type Nil (If BoolConst NumConst BoolConst) Num)')
            kb.ask ('(forall (t) (Type Nil BoolConst t))')
            kb.ask ('(forall (t) (Type Nil (If BoolConst NumConst NumConst) t))')
            # enumerate all expressions of type Num
            kb.ask ('(forall (t) (Type Nil t Num))')
            # test out function application, variable binding
            kb.ask ('(forall (t) (Type (Cons (Bind W Bool) (Cons (Bind V Num) Nil)) (Var V) t))')
            kb.ask ('(forall (t) (Type Nil (Fun X (If (Var X) NumConst NumConst)) t))')
            kb.ask ('(forall (t) (Type Nil (App (Fun X (If (Var X) NumConst NumConst)) BoolConst) t))')
            # infer type of (lambda (x) x)
            kb.ask ('(forall (t) (Type Nil (Fun X (Var X)) t))')
            # NO
            kb.ask ('(Type Nil (Fun X (App (Var X) (Var X))) Num)')
            # this will fail because we left *in* the occurs check
            kb.ask ('(forall (t) (Type Nil (Fun X (App (Var X) (Var X))) t))')
        kb.ask ('(forall (t)'
                '   (Type Nil (App (Fun Id (If (App (Var Id) BoolConst)'
                '                              (App (Var Id) BoolConst)'
                '                              (App (Var Id) BoolConst)))'
                '                   (Fun X (Var X)))'
                '              t))')

    @staticmethod
    def test14_FC():
        kb = horn_knowledge_base()
        kb.tell ('(forall (x y z) (=> (and (American x) (Weapon y) (Sells x y z) (Hostile z)) (Criminal x)))')
        kb.tell ('(American West)')
        kb.tell ('(exists (x) (and (Owns Nono x) (Missile x)))')
        kb.tell ('(forall (x) (=> (Missile x) (Weapon x)))')
        kb.tell ('(forall (x) (=> (and (Missile x) (Owns Nono x)) (Sells West x Nono)))')
        kb.tell ('(forall (x) (=> (Enemy x America) (Hostile x)))')
        kb.tell ('(Enemy Nono America)')
        kb.dump()
        
        
        FOL_FC_ASK(kb, ('Criminal','West'))

    
    @staticmethod
    def test15_BC():
        kb = horn_knowledge_base()
        kb.tell ('(forall (x y z) (=> (and (American x) (Weapon y) (Sells x y z) (Hostile z)) (Criminal x)))')
        kb.tell ('(American West)')
        kb.tell ('(exists (x) (and (Owns Nono x) (Missile x)))')
        kb.tell ('(forall (x) (=> (Missile x) (Weapon x)))')
        kb.tell ('(forall (x) (=> (and (Missile x) (Owns Nono x)) (Sells West x Nono)))')
        kb.tell ('(forall (x) (=> (Enemy x America) (Hostile x)))')
        kb.tell ('(Enemy Nono America)')
        kb.dump()
        print
    
        result=FOL_BC_ASK(kb, [('Criminal','West')])
        print "\n\nFOL-Backward Chaining :\nThe system is %s satisfied \nanswers=%s " % ("" if result["OK"] else "not",str(result["answers"]))
    
    @staticmethod
    def test16_otter():
        kb = knowledge_base()
        kb.tell ('(forall (x y z) (=> (and (American x) (Weapon y) (Sells x y z) (Hostile z)) (Criminal x)))')
        kb.tell ('(American West)')
        kb.tell ('(exists (x) (and (Owns Nono x) (Missile x)))')
        kb.tell ('(forall (x) (=> (Missile x) (Weapon x)))')
        kb.tell ('(forall (x) (=> (and (Missile x) (Owns Nono x)) (Sells West x Nono)))')
        kb.tell ('(forall (x) (=> (Enemy x America) (Hostile x)))')
        kb.tell ('(Enemy Nono America)')
        kb.dump()
        
        result=thm_provers("(Criminal West)",kb)
        


if __name__ == '__main__':
    import sys
    sys.setrecursionlimit (100)
    #Test.test2_to_cnf()
    #Test.test3_sld_resolution()
    #Test.test4_linear_resolution()
    #Test.test5_linear_resolution()
    #Test.test6_linear_resolution()
    #Test.test7_linear_resolution()
    #Test.test8_towers_of_hanoi()
    #something goes weird with this test and variable substitution
    #Test.test9_ask()
    #Test.test11_linear_resolution()
    #Test.test12_ask()
    #Test.test13_ask()
    #Test.test14_FC()
    #Test.test15_BC()
    Test.test16_otter()