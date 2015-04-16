# DFA

Discrete finite automata.

<http://en.wikipedia.org/wiki/DFA_minimization>

Recognize the same languages as regular grammars.

## Minimization

It is possible algorithmically minimize a DFA to an equivalent one with the smallest possible number of states.

The minimum is unique up to renaming, so it is also a good canonical form.

Hopcroft (1971) in $O(n log n)$ .

## Non-deterministic

Equivalent power to deterministic, proved with definition in 1959.

Interestingly, the same is not the case for:

- push down automata, in which deterministic are less powerful than non-deterministic
- omega automatons

Turing machines are also equivalent to NTMs, but the change alters the complexity of computations.

## Omega automaton

<http://en.wikipedia.org/wiki/%CE%A9-automaton>

Look just like automaton, but with one of several rules for what it means to accept a finite input.

Non-deterministic is strictly more powerful than deterministic in this case.
