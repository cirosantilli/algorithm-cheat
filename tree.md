# Tree

Trees are special cases of directed connected graphs that have the properties:

- no loops
- a root: there is a special node called the root. Any root you take on a tree generates a new different tree.

The great advantage of tree is perhaps the ability to create balanced trees which have `O(log(n)` height.

It also simplifies search procedures since you don't need to check if you have already visited some nodes, as there can be no loops.

Trees have $E = V - 1$.

## BST

## Binary search tree

Each node has 2 children.

Not necessarily balanced, so bounds for all operations is $O(n)$, although average times are $long(n)$.

There are balanced search trees such as RB-tree which actually have $O(ln)$ for all operations.

The only complicated operation is delete, visualize it here: <http://www.algolist.net/Data_structures/Binary_search_tree/Removal>

## Array-backed binary tree

<http://en.wikipedia.org/wiki/Binary_tree#Arrays>

Represents the tree as:

            1
        2      3
      4   5  6   7

On the array it becomes:

    1 2 3 4 5 6 7

Then:

- `child[i][0] == array[2*i]`
- `child[i][1] == array[(2*i + 1]`
- `parent[i] == array[(i/2)]`

Upside: memory efficient. Don't store any pointers: only the raw data.

Downside: BST operations like insert and rebalance are expensive as they requires to move lots of array elements around.
