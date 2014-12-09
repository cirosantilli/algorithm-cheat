# Context-free grammar

Related automaton: PDA.

## Application

Sufficient for most programming languages, while regexes are not.

But simpler than a context sensitive grammar.

Usually, programming languages are faster to parse subsets of CFG
most notably deterministic context free grammars,
which parse in $O(n)$) instead of $O(n^3)$.

## Complexity

CYK is the most widely used algorithm and recognizes it in $O(n^3)$.
It is practically good, but better asymptotic already known.

Parsing CGFs and multiplying 0/1 matrix algorithms are almost time Valiant (1975) equivalent:

-   Valiant (1975) has a method that given a multiplication algorithm,
    it can be converted into a parsing algorithm of the same complexity

-   somewhat conversely, Lee (2002) proved that any parsing algorithm in $O(n^{3-c})$
    can be converted into a matrix multiplication algorithm of $O(n^{3-c/3})$

Therefore the optimal time is linked to matrix multiplication,
which is still an open problem, but conjectured to have largest
lower bound 2, even if the best algorithms known are at around $O(n^2.37)$
with huge constant terms.

In practice however, CYK is still the most used algorithm as of 2014.

## Normal form

TODO

## Ambiguity

## Inherently ambiguous languages

Although some CFLs have both an ambiguous and non ambiguous representation,
there are others which only have ambiguous representations.
Such languages are called inherently ambiguous languages.

Their existence was first proved by <https://en.wikipedia.org/wiki/Parikh%27s_theorem> (1961).

## Undecidable problems

There are lots of interesting ones:

### Universality

Given a CFG, does it generate the language of all strings over the alphabet
of terminal symbols used in its rules.

Equivalence with one side fixed.

### Equivalence

Given two CFG, do they accept the same language?

Decidable $O(n)$ for regular expressions, and decidable for DPDA.

### Language inclusion

Given two CFG, is one language included in the other?

### Inclusions on Chomsky hierarchy

Given a CSG, is it a CFG?

Given a CFG, is it a regex?

### Ambiguity detection

Given a CDG, is it ambiguous?

## Extended context-free grammar

Grammar in which each right hand side can be a regex.

Same languages as context-free grammars, since regular expressions are contained in context-free grammars.

Convenient because it represents well what most parsers do today: first a regex tokenization step, then parse.

## Deterministic context-free grammar

Same as non-deterministic, but with deterministic automaton.
