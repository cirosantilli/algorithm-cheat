# Formal languages

A language is a set of strings.

A grammar for a language is a set of rules that produces exactly that language.
It is not easy, given a grammar and a string, to find out how the grammar can generate the string,
because at each step there are many possible actions.

## Chomsky hierarchy

<https://en.wikipedia.org/wiki/Chomsky_hierarchy>

Famous hierarchy of certain languages that are strictly contained in each other.

The original hierarchy contains only:

| Grammar                | Automaton                                       | Production rules                                 |
|------------------------|-------------------------------------------------|--------------------------------------------------|
| Recursively enumerable | Turing machine                                  |                                                  |
| Context-sensitive      | Linear-bounded non-deterministic Turing machine | $\alpha A \beta \rightarrow \alpha \gamma \beta$ |
| Context-free           | Non-deterministic pushdown automaton            | $A \ rightarrow \gamma$                          |
| Regular                | Finite state automaton                          | $A \rightarrow a$ and $A \rightarrow aB$         |

There are however many other well known languages in between those classes.

- finite language: contains only a finite number of words. Strict subset of Regular.
- [LL](https://en.wikipedia.org/wiki/LL_grammar), and the related LR, SLL, SLR. Useful subset of context-free. Related automaton: DPDA.

## Category of popular languages

- C and C++ are ambiguous and cannot be parsed by $LR(1)$, but can be parsed by GLR: <http://stackoverflow.com/questions/243383/why-cant-c-be-parsed-with-a-lr1-parser>
