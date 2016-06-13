import re

is_lang = re.compile("^(C|CPP|JAVA|PYTHON|PERL|PHP|RUBY|CSHARP|HASKELL|CLOJURE|BASH|SCALA|ERLANG|CLISP|LUA|BRAINFUCK|JAVASCRIPT|GO|D|OCAML|R|PASCAL|SBCL|DART|GROOVY|OBJECTIVEC)$")

for t in xrange(input()):
    _,lang = raw_input().split()
    if is_lang.match(lang):
        print "VALID"
    else:
        print "INVALID"
