# Change making

<http://en.wikipedia.org/wiki/Change-making_problem>

Knapsack-like problem where:

- each weight is fixed to 1
- the goal must be reached exactly
- infinite supply of items

Even the feasibility is NP-complete.

If the input set is <http://en.wikipedia.org/wiki/Superincreasing_sequence>, like the coin denomination of most countries, then the greedy algorithm works. This is why there is cannot be a 3 euro coin: otherwise 3 + 2 + 1 = 6 > 5, and change making would be NP-complete.

## Implementations

- [make_change.cpp](src/cpp/make_change.cpp)

## Bibliography

- <https://web.archive.org/web/20131007212811/http://www.or.deis.unibo.it/kp/Chapter5.pdf>
