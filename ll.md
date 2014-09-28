# LL parser

Efficient to parse strict subset of context-free.

Many popular languages are designed to be $LL(1)$.

TODO find a list of popular languages that are $LL(1)$ and a list of those which are not.

TODO understand, example.

DPDAs are the related automatons.

## LL(*) star

Can look ahead by regular languages instead of finite numbers of characters.

## Ambiguity

$LL(k)$ grammars are unambiguous.

## Recursive descent parser

TODO

## Related languages

Relationships: <http://cs.stackexchange.com/questions/43/language-theoretic-comparison-of-ll-and-lr-grammars>

### LR parser

Cannot be ambiguous.

$LL(k) \subsetneq LR(k)$, Rosenkrantz (1969).

$LR(0) \subsetneq LR(1) = LR(n)$

Unambiguous.

### SSR

### SSL

TODO

### LALR

$LALR(k)$ is incomparable with $$LL(k)$.

TODO

### GLR

<https://en.wikipedia.org/wiki/GLR_parser>

TODo
