#application

sufficient for most programming languages, while regexes are not

but simpler than a context sensitive grammar

usually, programming languages are faster to parse subsets of CFG
most notably deterministic context free grammars
(which parse in O(n)) instead of O(n^3) )

#automaton

pushdown automata (*non deterministic*)

#recognition complexity

CYK: O(n^3), practically good, but better assymptotic known

parsing CGFs and mutliplying 0/1 matrix algorithms are almost time equivalent

therefore the optimal time is linked to matrix multiplication,
which is still an open problem, but conjectured to have largest
lower bound 2, even if the best algorithms known ar at around O(n^2.37)
with huge constant terms

#normal form

TODO

#undecidable problems

there are lots of interesting ones:

##universality

Given a CFG, does it generate the language of all strings over the alphabet of terminal symbols used in its rules

##language equality

Given two CFG, do they accept the same language?

decidable O(n) for regular exapressions!

##language inclusion

Given two CFG, is one language included in the other?

##chomsky hierarchy

Given a CSG, is it a CFG?
Given a CFG, is it a regex?

##ambiguity

Given a CDG, is it ambiguous?

#amibtuity

certain languages can only be recognized by ambiguous grammars

#extended context-free grammar

grammar in which each right hand side can be a regex

same languages as context-free grammars

exactly what the lex/yacc pair does

it does that for one reason: separating complexities

#deterministic context-free grammar

same as non deterministic, but with deterministic automaton
