# Trie

# Prefix tree

<http://en.wikipedia.org/wiki/Trie>

<https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/>

## Vs other maps

Advantages

-   can search by prefix
-   easier to search for:
    - missing characters
    - exchanged characters

Disadvantages:

-   I think tries take up more space. For each level, you have to store an array with ALL the possible numbers.

    -   a large alphabet is less space efficient and faster (go down less levels).

        An infinite alphabet is an array: O(1) worst case retrieval.

    -   a single bit alphabet (2 paths per node) is equivalent to TODO: I think a BST, if we compress it into a radix tree.

    -   a zero bit alphabet (1 path per node) is equivalent to TODO: I think a linked list, if we compress it into a radix tree.

Bibliography:

- <http://stackoverflow.com/questions/245878/how-do-i-choose-between-a-hash-table-and-a-trie-prefix-tree>

### Vs B-Tree

B-tree also have a branching factor parameter similar to alphabet size:

- <http://stackoverflow.com/questions/2688639/trie-vs-b-tree>

The major difference seems to be do you want to make:

- X is between Y and Z queries? Then B-Tree.
- X has prefix Y queries? Trie.

## Patricia trie

Some people differentiate it, others not:

- <http://stackoverflow.com/a/15906358/895245>
