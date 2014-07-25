# Regular expressions

Formal regex: only (|), concatenation and `*` operations possible.

## Extensions

Practical Regex implementations offer several extensions, some of which are reducible
to formal regexes, and others which are not and increase the capacity of the language,
while reducing theoretical performance.

### Predefined classes

`.`, `\s`, etc.

Obviously can be simply expanded into the base refs

### ? and +

Are directly defined in terms of the base operations.

### {n,m}

Can be expanded into a huge number of `|`.

Example:

    a{2,4}

Equals:

    aa(|a(|a)))

### Lazy matching

E.g.: `.*?` or `.+?` in Perl.

This concept does not exist in formal regexes since lazyness is only useful to remove ambiguity
to predict the content of capturing groups, concept which does not exist in formal regexes

### Backreferences

Example: `(.*)\1.`, matching `aa`, `abab`.

Classic non regex thing, but possible in context free.

## Pumping lemma

### Application

Regexes cannot do parenthesis matching (you need context free for that).

Also proves many other languages are not context free.

## Complexity

The main algorithms follow.

### DFA

Best time, but exponential space.

First transforms into a DFA.

- $O(n)$ time once you transformed it into a deterministic finite automaton
- $O(2^n)$ memory 

Then $O(n)$ time to do the transformation (compile the regex).

This can always be done because there is always a regex equivalent to DFA,
and the equivalence can be done in $O(n)$.

##### Smallest automaton can be exponentially larger than a regex length

Example: $L_k$ family.

Importance of this fact: $O(n)$ regex recognition is $O(2^n)$ memory.

### Lazy DFA

Build DFA and discard states on the fly.

$O(mn^2)$ time and polynomial space.

### Backtracking

Exponential time.

#### Often used in implementations because

##### Non exponential space

##### Easier to code extra features such as group matching

## DFA minimization

$O(n log n)$ by Hopcroft 71.

Minimization is unique (least numer of states).

#### Application: reduce memory usage in regexes

## Ambiguity

Can always be removed

Example:

    (ab|a)(b|ab)

is ambiguous, since `aba` can be done in two ways.

The equivalent:

    a(b|b(a|b))

recognizes the same language but is not ambiguous.

### Meaning of ambiguous

There are more than one way to reach a single string by deciding:

- which side of `|` to take
- how many times to expand `a*`

### Complexity of resolving ambiguity

TODO time complexity of resolving ambiguity

## Regex equivalence

$O(n)$ by Hopcroft-Krap 73.

Classically $O(n log n)$, using DFA minimization/isomorphism.

### Application: ensure that a simpler regex does the same as a complicated one

## Star height problem

<http://en.wikipedia.org/wiki/Star_height_problem>

Nested level of Kleene stars:

- `(a|b)*`:        star height 1
- `((a|b*)*` :     star height 2
- `((a|b*)a|b*)*`: star height 3

Problems posed:

-   Is finite star height enough all regexes?
    1966: no, counter example family given.

-   Computing star height of a given sequence. Much harder.
    First answer: Hashiguchi 1988, not in ELEMENTARY.
    Kirsten 2005: double exponential.
