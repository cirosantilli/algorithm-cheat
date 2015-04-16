# Graph

## E and V

E = set of edges

V = set of vertices

$|E|$: number of edges

$|V|$: number of vertices

Important relation:

- $0 <= E <= V^2$, and for connected graphs: $|V| - 1 <= |E| <= |V|^2$. If equality happens, the graph is said to be dense.

- if $|E| > (V - 1)(V - 2)/2$ then it must be connected.

- $\forall y, |{ xy | x \in V }| <= V - 1$ for a fixed $i$ and $x$ free to vary.

## Tree

Trees are special cases of directed connected graphs that have the properties:

- no loops
- a root: there is a special node called the root. Any root you take on a tree generates a new different tree.

The great advantage of tree is perhaps the ability to create balanced trees which have `O(log(n)` height.

It also simplifies search procedures since you don't need to check if you have already visited some nodes, as there can be no loops.

Trees have $E = V - 1$.

### BST

### Binary search tree

Each node has 2 children.

Not necessarily balanced, so bounds for all operations is $O(n)$, although average times are $long(n)$.

There are balanced search trees such as RB-tree which actually have $O(ln)$ for all operations.

The only complicated operation is delete, visualize it here: <http://www.algolist.net/Data_structures/Binary_search_tree/Removal>

### Array-backed binary tree

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

## DFS

## Depth first search

DFS can be done either recursively or not with a stack.

The only key difference is that the recursive version uses the system's call stack, while the non-recursive version uses an explicit stack.

## BFS

## Breadth first search

BFS cannot be done recursively naturally, since the non-recursive implementation uses a queue, and not a stack like DFS.

<http://stackoverflow.com/questions/2549541/performing-breadth-first-search-recursively>

## DFS vs BFD

Both are methods to search vertexes on unordered graphs.

Advantages of DFS:

-   if the searched solutions are guaranteed to be at the greatest depths (e.g. leaves of a tree) then DFS will certainly be faster.

-   if the graph is somehow balanced (nodes of maximum depth are at similar depths), then DFS will certainly use less memory than BFS since BFS must store a FIFO of each level ($2^depth$ vertexes on a balanced binary tree) while BFS stores at most the maximum depth sequence of parents ($depth$ elements).

    Iterative deepening DFS may be used to reduce memory usage of the regular DFS.

Advantages of BFS:

-   it is the obvious choice when looking for minimum distances, since you want to keep as close as possible to the start and not go too deep.

-   if the depth can be too long, or even infinite, it is simpler to look breadth first, and limit the descent, or the process could take forever or too long.

    It also makes more sense to use heuristics with BFS, looking around the current position, and then deciding where to descend further.

### IDDFS

### Iterative deepening DFS

<https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search>

Do depth-limited searches with increasing height.

The best only possibility when `2^height` is too much for your RAM, and uses just `O(height)` for the backtracking. Downside: way slower.

This also implies of course that the graph does not fit into memory, so that you have to think about how to 

It is not feasible to keep track of the visited notes because that would take up too much memory. Infinite loops are voided by the depth limiting.
