#E and V

E = set of edges

V = set of vertices

`|E|`: number of edges

`|V|`: number of vertices

Important relation:

- `|E| <= |V|^2`. If equality happens, the graph is said to be dense.

- `\forall y, |{ xy | x \in V }| <= |V|-1` for a fixed i and x free to vary.

#Tree

Trees are special cases of directed connected graphs that have the properties:

- no loops
- root: there is a distinguished node from which every other node is reachable

This immediately implies that E = V - 1, and simplifies search procedures since you don't need to check if you have already visited some nodes.

##BST

##Binary search tree

Each node has 2 children.

Not necessarily balanced, so bounds for all operations is $O(n)$, although average times are $long(n)$.

There are balanced search trees such as [RB-tree](red-black-tree) which actually have $O(ln)$ for all operations.

The only complicated operation is delete, visualize it here: <http://www.algolist.net/Data_structures/Binary_search_tree/Removal>

##RB-tree.

##Red black tree

Balanced binary search tree.

Red black tree are binary search trees that support element query, insertion and deletion in $log(n)$ time.

All that is needed is to store one extra bit per node: red or black.

It must have the following properties:

- A node is either red or black.
- The root is black.
- All leaves (NIL) are black.
- Both children of every red node are black.

    Children of a black node can have any color.

- Every simple path from a given node to any of its descendant leaves contains the same number of black nodes.

A leaf is not a node and a node is not a leaf in this context. Nodes contain the actual numbers that are being indexed, leafs don't contain any information, except indicating that there are no more nodes below.

Leafs in this context are also called sentinels.

Operations are $log(n)$ because the properties imply that the tree is balanced in the sense that the deepest leaf from a node can only be twice as deep as the shallowest one.

The key to using the tree is keeping it balanced after insertion or deletion.

Live Java applet demo: <http://www.ece.uc.edu/~franco/C321/html/RedBlack/>. Requires a bit too many clicks, but really cool.

TODO visualize insert

#DFS

DFS can be done either recursively or not with a stack.

The only key difference is that the recursive version uses the system's call stack, while the non-recursive version uses an explicit stack

#BFS

BFS cannot be done recursively naturaly, since the non-recursive impementation uses a queue, and not a stack like DFS.

<http://stackoverflow.com/questions/2549541/performing-breadth-first-search-recursively>

#DFS vs BFD

Both are methods to search vertexes on unordered graphs.

On a general graph, you must keep track of which nodes you have already looked into not to go on loops, so you need to add a search bit to each vertex.

On trees (specific type of graph) this is not needed since trees have no loops by definition.

Advantages of DFS:

- if the searched solutions are guaranteed to be at the greatest depths (ex leaves of a tree) then DFS will certainly be faster.

- if the graph is somehow balanced (nodes of maximum depth are at similar depths), then DFS will certainly use less memory than BFS, since BFS must store a FIFO of each level ($2^depth$ vertexes on a balanced binary tree) while BFS stores at most the maximum depth sequence of parents ($depth$ elements).

Advantages of BFS:

- it is the obvious choice when looking for minimum distances, since you want to keep as close as possible to the start and not go too deep.

- if the depth can be too long, or even infinite, it is simpler to look breadth first, and limit the descent, or the process could take forever or too long.

    It also makes more sense to use heuristics with BFS, looking around the current position, and then deciding where to descend further.

#Dijkstra

<http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm>

Find the shortest path between two given nodes.

Only works if all weights are positive. If negative weights are possible, consider using the [bellman ford algorithm](http://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm).

##Dijkstra complexity

Time worst case: $O(|E| + |V| log |V|)$, so $O(|V|^2)$ on a dense graph.

In the worst case we have a dense graph and we must visit all the nodes giving:

- `FOR_VERTEX`: for each vertex ($|V|$):

    - `MARK_VISITED`: mark vertex as visited.

    - `FOR_NEIGHBOUR`: for each neighbour: $|O(\sqrt(|E|))|$, $|V|$ for a dense graph.

        - UPDATE_WEIGHT: update the weights of that neighbour

    - FIND_MIN: find the minimum adjacent element to determine the next vertex

Lets consider two data structure possibilities for storing node distances and if it was visited or not:

- unordered array
- min heap

###Unordered array

Vertexes and their distances are stored in an array ordered by their index.

- `MARK_VISITED`    is done in $O(1)$: just set the corresponding array element visited field to true.
- `UPDATE_WEIGHT`   can be done in time $O(1)$ if the vertexes are on an unordered array.
- `FIND_MIN`        takes $O(V)$ since the elements are not ordered by distance

Total time:

$$
    FOR_VERTEX * ( MARK_VISITED + ( FOR_NEIGHBOUR * UPDATE_WEIGHTS    ) + FIND_MIN    ) =
    V *          ( 1            + ( V             * 1                 ) + V           ) =
    V^2
$$

operations.

###Min heap

We order the vertexes on a min heap that takes the distance into account.

The complexity will depend on the type of min heap used. We consider there the two most commmon and efficient min heaps for practical data sizes:

- binary heap
- Fibonacci heap

TODO get this right

- `MARK_VISITED`    means that we have to remove the root element from the min heap:

    - Binary heap:    `log`
    - Fibonacci heap: `n` worst case, `log` amortized

- `UPDATE_WEIGHT`  this critical operation depends on the type of min heap used.

    - Binary heap:    `log`
    - Fibonacci heap: `log` worst case, `1`

- `FIND_MIN`        always $O(1)$ since we are using heaps

Therefore for the binary heap:

$$
    FOR_VERTEX * ( MARK_VISITED + ( ( FOR_NEIGHBOUR * UPDATE_WEIGHTS ) + FIND_MIN ) =
    V *          ( log(V)       + ( ( V             * log V          ) + 1        ) =
    V^2 log(V)
$$

and for fibonacci amortized time:

$$
    FOR_VERTEX * ( MARK_VISITED + ( ( FOR_NEIGHBOUR * UPDATE_WEIGHTS ) + FIND_MIN ) =
    V *          ( log(V)       + ( ( V             * 1              ) + 1        ) =
    V^2
$$

##Choice of data structure

The final choice of the data structure will depend on the expected density of the graph:

- if the graph is expected to be dense, use an unordered array, as it has the best wort time for that case, while a Fibonacci heap offers only

- if the graph is known to be sparse, $degree(v) <<< V/log(V)$, then the ordered approch starts being better.

- If amortized time can be taken into account and it is not clear if the graph is dense or not, the Fibonnaci Heap implementation  is the best option, as it:

    - works as well as the unordered array implementation
    - for dense graphs, and better if the graph is not dense (often the case).

#A star

aka `A*`

Does the same as Dijkstra, but supposes that extra knowledge is known about the graph.

That extra knowledge is an estimative $h$ of distance between the current node and the target such as the straight line or manhattan distance.

The algorithm then first explores nodes with lowest: $current distance + h(next node)$

Good tutorial:

- <http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html>

Let $h(x)$ be the estimative.

- $h(x)$ is always smaller than the actual distance to goal: convergence guaranteed.

- $h(x) = 0$: same as Dijkstra

- $h(x)$ is the exact distance to destination: only the correct path is explored.

#Bellman-ford

Does the same as Dijkstra, but

- larger time complexity: $n^2 log n$
- also works for graphs with negative weights
