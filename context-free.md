# Context-free grammar

## Application

Sufficient for most programming languages, while regexes are not.

But simpler than a context sensitive grammar.

Usually, programming languages are faster to parse subsets of CFG
most notably deterministic context free grammars,
which parse in $O(n)$) instead of $O(n^3)$.

## Automaton

Pushdown automata (*Non deterministic*).

## Recognition complexity

CYK algorithm: $O(n^3)$, practically good, but better asymptotic already known.

Parsing CGFs and multiplying 0/1 matrix algorithms are almost time equivalent.

Therefore the optimal time is linked to matrix multiplication,
which is still an open problem, but conjectured to have largest
lower bound 2, even if the best algorithms known are at around $O(n^2.37)$
with huge constant terms

## Normal form

TODO

## Undecidable problems

There are lots of interesting ones:

### Universality

Given a CFG, does it generate the language of all strings over the alphabet
of terminal symbols used in its rules.

### Language equality

Given two CFG, do they accept the same language?

Decidable O(n) for regular expressions!

### Language inclusion

Given two CFG, is one language included in the other?

### Chomsky hierarchy

Given a CSG, is it a CFG?
Given a CFG, is it a regex?

### Ambiguity

Given a CDG, is it ambiguous?

## Ambiguity

Certain languages can only be recognized by ambiguous grammars.

## Extended context-free grammar

Grammar in which each right hand side can be a regex.

Same languages as context-free grammars.

Exactly what the lex/yacc pair does.

It does that for one reason: separating complexities.

## Deterministic context-free grammar

Same as non deterministic, but with deterministic automaton.
