# Hash map

## Hash map vs BST

<http://stackoverflow.com/questions/371136/binary-trees-vs-linked-lists-vs-hash-tables>

Hash map:

-   more efficient search / insert than trees: $O(1)$ amortized with a perfect hash function, $O(1)$ average with a uniform random hash function

-   worse worst case search / insert $O(n)$ vs $O(log(n))$

    Search comes from a bad hash function with many conflicts.

    Insert comes from the rehashes.

-   takes up more memory than then number of elements because it must have an array of entries, and it must usually be at least 50% larger than the actual number of entries.

-   no ordered transversal

-   harder to implement because a good hash function must be chosen

## Open addressing

Good sources on open addressing:

- <http://webdocs.cs.ualberta.ca/~holte/T26/open-addr.html>
- <http://www.algolist.net/Data_structures/Hash_table/Open_addressing>

Open addressing vs. chaining:

-   Collision resolution.

    Using external data structure.

    Using hash table itself.

-   Memory waste:

    - Pointer size overhead per entry (storing list heads in the table).

    - No overhead 1.

-   Performance dependence on table's load factor

    - Directly proportional

    - Proportional to $(loadFactor) / (1 - loadFactor)$

-   Allow to store more items, than hash table size

    - Yes.

    - No. Moreover, it's recommended to keep table's load factor below 0.7.

-   Hash function requirements

    - Uniform distribution.

    - Uniform distribution, should avoid clustering.

-   Handle removals

    - Removals are OK.

    - Removals clog the hash table with "DELETED" entries.

-   Implementation

    - Simple.

    - Correct implementation of open addressing based hash table is quite tricky.
