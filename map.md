# Map

<http://en.wikipedia.org/wiki/Associative_array>

Abstract data structure.

Major implementations:

- hash map
- balanced binary search tree

## Hash map vs BST

<http://stackoverflow.com/questions/371136/binary-trees-vs-linked-lists-vs-hash-tables>

Hash map:

-   more efficient search / insert than trees: $O(1)$ amortized

-   worse worst case search / insert $O(n)$ vs $O(log(n))$

    Search comes from a bad hash function with many conflicts.

    Insert comes from the rehashes.

-   harder to implement because a good hash function must be chosen

-   no ordered transversal
