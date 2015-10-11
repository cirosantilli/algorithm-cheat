# String algorithms

Algorithms that operate on sequences of bytes.

## Terminology

### Subsequence

### Substring

Substrings are contiguous, subsequences not necessarily.

Substrings are therefore a particular case of subsequences.

<http://en.wikipedia.org/wiki/Subsequence>

<http://en.wikipedia.org/wiki/Substring>

## Data structures

Data structures that are useful to solve string problems.

## Suffix tree

<http://en.wikipedia.org/wiki/Suffix_tree>

String pre processing that allows for efficient solution of other string problems, e.g.:

- string search
- find longest repeated substring
- find longest common substring
- find longest palindrome substring

Concept introduced in 1973, but efficient algorithms for it's generation are non-trivial. First linear time algorithm (thus optimal) created by Farach (1997).

### Banana example

Take the input string `banana`.

### Trie

<http://en.wikipedia.org/wiki/Trie>

TODO constructions, algorithms

TODO: vs binary search tree?

TODO: vs <http://en.wikipedia.org/wiki/Deterministic_acyclic_finite_state_automaton>? DAFSA is strictly smaller, but you have to optimize the automaton: 

## Famous problems

### Longest common substring

<http://en.wikipedia.org/wiki/Longest_common_substring_problem>

### Longest increasing substring

<http://en.wikipedia.org/wiki/Longest_increasing_subsequence>

### String metrics

### String distances

<http://en.wikipedia.org/wiki/String_metric>

The length of the already implemented longest common subsequence result is a metric, although it is too local to be practically used as a metric.

Subjective as application dependant, and the only thing to optimize is to match "what humans think is sensible".

Formal definitions set the basic operations, and what must be optimized.

#### Levenshtein distance

-   <http://en.wikipedia.org/wiki/Levenshtein_distance>

The most famous string metric. Operations: single char addition, deletion and substitution. Dynamic programming algorithm.

-   <http://en.wikipedia.org/wiki/String_searching_algorithm>

### Sequence alignment

<http://en.wikipedia.org/wiki/Sequence_alignment> seem to be string search algorithms with more complex metrics. Used in practice in bioinformatics.

<https://en.wikipedia.org/wiki/Smith%E2%80%93Waterman_algorithm> is a famous one.

### Longest repeated substring problem

<http://en.wikipedia.org/wiki/Longest_repeated_substring_problem>

### Shortest non-substring

Of a single string:
<http://cs.stackexchange.com/questions/21896/algorithm-request-shortest-non-existing-substring-over-given-alphabet>

Of multiple strings:
<http://cs.stackexchange.com/questions/39687/find-the-shortest-string-that-is-not-a-sub-string-of-a-set-of-strings>

### Approximate string matching

<http://en.wikipedia.org/wiki/Approximate_string_matching>

Set of techniques to find similar strings according to some metric.
