# Graph

<http://en.wikipedia.org/wiki/Graph_%28abstract_data_type%29>

## Properties

### Relations between E and V

E = set of edges

V = set of vertices

$|E|$: number of edges

$|V|$: number of vertices

Important relation:

- $0 <= E <= V^2$, and for connected graphs: $|V| - 1 <= |E| <= |V|^2$. If equality happens, the graph is said to be dense.

- if $|E| > (V - 1)(V - 2)/2$ then it must be connected.

- $\forall y, |{ xy | x \in V }| <= V - 1$ for a fixed $i$ and $x$ free to vary.

## Transversals

### DFS

### Depth first search

DFS can be done either recursively or not with a stack.

The only key difference is that the recursive version uses the system's call stack, while the non-recursive version uses an explicit stack.

### BFS

### Breadth first search

BFS cannot be done recursively naturally, since the non-recursive implementation uses a queue, and not a stack like DFS.

<http://stackoverflow.com/questions/2549541/performing-breadth-first-search-recursively>

### DFS vs BFD

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

## Attributes

Graph structures must be able to contain arbitrary attributes associated to each edge (node pair), and this is their major design concern.

For example:

-   on a shortest path problem, the only edge attributes is the width of an edge.

-   on a city, each street takes a time to cross, and has a different length.

    The two are not necessarily proportional since some streets have more traffic than others.

    Cover the maximum length withing a fixed amount of time.

    In this problem, each edge must have 2 integers associated to it: length and time to cross.

Node attributes are simpler to deal with as they can just be stored into a single array of properties.

Dynamic operations such as addition and removal of edges and nodes are also required, but often less important, as many practical graph problems are based on static graphs.

## Implementations

There are two major graph implementations:

- adjacency list
- adjacency matrix

### Adjacency list

Represent nodes by integers. For each node, store what it points to.

-   directed implementation: array of destination to properties maps:

        g[origin0] = {dest00: properties00, dest01: properties01}.
        g[origin1] = {dest10: properties10, dest11: properties11}.
        ...

    Probably the best option in general, as it is `O(1)` average to get edge properties from an origin / destination pair.

-   undirected: same as above, but store every node pair as `(smaller, larger)`, and convert all inputs `(larger, smaller)` to `(smaller, larger)`.

### Adjacency matrix

Keep a matrix of edge properties.

Advantage: `O(1)` worst time to access each edge properties from node pair.

Disadvantage: `O(n^2)` memory, regardless of graph density.

This method is generally less useful because:

- most graphs encountered in practice are very sparse, so the matrix will contain too many 0 entries.
- adjacency list implementation can already reach `O(1)` average time (but not worst).
