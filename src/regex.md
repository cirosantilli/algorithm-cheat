Formal regex: only (|), concat and * ops

#extensions

regex packages offer some extensions of regexes:

##predefined classes

``.``, ``\s``, etc.

obviously can be simply expanded into the base refs

##? and +

are directly defined in terms of the base ops

##{n,m}

can be expanded into a huge number of ``|``

ex:

    a{2,4}

equals:

    aa(|a(|a)))

##lazy matching

ex: ``.*?`` or ``.+?`` in perl

this concept does not exist in formal regexes
since lazyness is only useful to remove ambiguity
to predict the content of capturing groups,
concept which does not exist in formal regexes

##backreferences

example: ``(.*)\1.``, matching aa, ``abab``.

classic non regex thing, but possible in context freeK

#pumping lemma

##application

regexes cannot do parenthesis matching (you need context free for that)

also proves many other languages are not context free

#complexity

the main algorithms are:

##DFA

best time, but exponential space

first transforms into a dfa

O(n)         time once you transformed it into a deterministic finite automaton
O(2^n) memory 

O(n) time to do the transformatino (compile the regex)

this can always be done because:

###regex equivalent to dfa

yes it is true, and can be done in O(n)

####smallest automaton can be exponentially larger than a regex length

example: L_k familly

importance of this fact: O(n) regex recognition is O(2^n) memory

##lazy DFA

build DFA and discard states on the fly

O(mn^2) time and polynomial space

##backtracking

exponential time!

###often used in implementations because

####non exponential space

####easier to code extra features such as group matching

#dfa minimization

O(n log n): Hopcroft 71

minimization is unique (least numer of states)

###application: reduce memory usage in regexes

#ambiguity

can always be removed

##exaple:

(ab|a)(b|ab)

is ambiguous, since `aba`
can be done in two ways

a(b|b(a|b))

recognizes the same language
but is not ambiguous

##meaning of ambiguous

there are more than one way to reach
a single string by deciding:

1) which side of | to take,
2) how many times to expand a*

##complexity of resolving ambiguity

TODO time complexity of resolving ambiguity

#regex equivalence

O(n) Hopcroft Krap 73 possible

classically O(n log n), using dfa minimization/isomorphism

##application: ensure that a simpler regex does the same as a complicated one

#star height problem:

(a|b)* :     star height 1
((a|b*)* : star height 2
((a|b*)a|b*)* : star height 3

posed in 1963

1) fininite star height is not enough for all langs
counter example family given

2) computing star height:
hashiguchi 1988, nontrivial, huge time complexity
kirsten 2005: double exponential!

application? TODO
