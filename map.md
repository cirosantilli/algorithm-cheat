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

-   takes up more memory than then number of elements because it must have an array of entries, and it must usually be at least 50% larger than the actual number of entries.

-   no ordered transversal

-   harder to implement because a good hash function must be chosen
