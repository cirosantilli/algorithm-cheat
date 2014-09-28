# Regular expression

Strings that describe regular languages.

Can be formally constructed recursively as:

- any terminal symbol is a regular expression
- the empty string is a regular expression

Then recursively, if `R` and `S` are regular expressions then the following are also:

- alternative: `(R|S)`
- concatenate: `RS`
- Kleene star: `R*`

This defines a new language, which can be efficiently parsed,
and transformed into a DFA or a regular grammar.

Regular expressions are as powerful as regular grammars.

## Extensions

Practical Regex implementations offer several extensions, some of which are reducible
to formal regexes, and others which are not and increase the power of the language,
while reducing theoretical performance.

### Predefined classes

`.`, `\s`, etc.

Obviously possible.

### Question mark ? and plus sign +

`?` and `+` can directly defined in terms of the base operations.

### Counted repetitions {n,m}

Can be expanded with a huge number of `|`.

Example:

    a{2,4}

Equals:

    aa(|a(|a)))

### Lazy matching .*?

E.g.: `.*?` or `.+?` in Perl.

This concept does not exist in formal regexes since laziness is only useful to remove ambiguity
to predict the content of capturing groups, concept which does not exist in formal regexes

### Backreferences

Example: `(.*)\1.`, matching `aa`, `abab`.

Classic non-regex thing because of the pumping lemma, but possible in context free.

## Pumping lemma

Application: regexes cannot do parenthesis matching,
therefore they are a strict subset of context-free languages
(a subset because you can express regular languages with context-free grammars).

Also proves many other languages are not context free.

## Complexity

### DFA implementation

DFAs have the Same power as regular expressions.

Regular expressions implementation has a better time performance,
but the number of states grows exponentially with regex size,
thus taking memory exponentially.

First a preprocessing step to transforms regex into a DFA.

Once that is done, matching takes:

- $O(n)$ time
- $O(2^n)$ memory

Then $O(n)$ time to do the transformation (compile the regex).

This can always be done because there is always a regex equivalent to DFA,
and the equivalence can be done in $O(n)$.

### Lazy DFA

Middle ground between DFA and backtracking implementation.

Build DFA and discard states on the fly.

$O(mn^2)$ time and polynomial space.

### Backtracking

Exponential time.

Often used in implementations because:

- non exponential space
- easier to implement extra features such as group matching
- in practice, most regular expressions are small

## Ambiguity

A regular expression is ambiguous when there are more than one way to reach a single string by deciding:

- which side of `|` to take
- how many times to expand `a*`

Can always be removed for regular expressions.

This is in contrast to context-free languages where there are inherently ambiguous languages.

Example:

    (ab|a)(b|ab)

is ambiguous, since `aba` can be done in two ways.

The equivalent:

    a(b|b(a|b))

recognizes the same language but is not ambiguous.

TODO algorithm and complexity of resolving ambiguity?

## Regex equivalence

Possible in $O(n)$ by Hopcroft-Krap (1973).

Naively obvious in $O(n log n)$, converting to DFA and minimizing since the minimum is unique.

Application: ensure that a simple regex does the same as a complicated one.

## Star height problem

<http://en.wikipedia.org/wiki/Star_height_problem>

The *star height* is the nested level of Kleene stars:

- `(a|b)*`:        star height 1
- `((a|b*)*` :     star height 2
- `((a|b*)a|b*)*`: star height 3

Problems posed:

-   Is finite star height enough all regexes?
    1966: no, counter example family given.

-   Compute star height of a given sequence. Much harder.
    First answer: Hashiguchi 1988, not in $ELEMENTARY$.
    Kirsten 2005: double exponential.
