#tree

Trees are special cases of directed connected graphs that have the properties:

- no loops
- root: there is a distinguished node from which every other node is reachable

This immediately implies that E = V - 1, and simplifies search procedures since you don't
need to check if you have already visited some nodes.

#binary search tree

aka BST.

Each node has 2 children.

Not necessarily balanced, so bounds for all operations is $O(n)$, although average times are $long(n)$.

There are balanced search trees such as [RB-tree](red-black-tree) which actually have $O(ln)$ for all operations.

The only complicated operation is delete, visualize it here: <http://www.algolist.net/Data_structures/Binary_search_tree/Removal>

#red black tree

aka RB-tree.

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

A leaf is not a node and a node is not a leaf in this context.
Nodes contain the actual numbers that are being indexed, leafs don't contain any information,
except indicating that there are no more nodes below.

Leafs in this context are also called sentinels.

Operations are $log(n)$ because the properties imply that the tree is balanced in the sense that
the deepest leaf from a node can only be twice as deep as the shallowest one.

The key to using the tree is keeping it balanced after insertion or deletion.

Live java applet demo: <http://www.ece.uc.edu/~franco/C321/html/RedBlack/>. Requires a bit too many clicks, but really cool.

TODO visualize insert

#DFS and BFD

Both are methods to search vertexes on unordered graphs.

On a general graph, you must keep track of which nodes you have already looked into not to go on loops,
so you need to add a bit to each vertex.

On trees (specific type of graph) this is not needed since trees have no loops by definition.

Advangates of DFS:

- if the searched solutions are guaranteed to be at the greatest depths (ex leaves of a tree)
    then DFS will certainly be faster.

- if the graph is somehow balanced (nodes of maximum depth are at similar depths),
    then DFS will certainly use less memory than BFS, since BFS must store a FIFO of each level
    ($2^depth$ vertexes on a balanced binary tree) while BFS stores at most the maximum depth
    sequence of parents ($depth$ elements).

Advangates of BFS:

- it is the obvious choice when looking for minimum distances,
    since you want to keep as close as possible to the start and not go too deep.

- if the depth can be too long, or even infinite, it is simpler to look breadth first,
    and limit the descent, or the process could take forever or too long.

    It also makes more sense to use heuristics with BFS, looking around the current position,
    and then deciding where to descend further.

#dijikstra

<http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm>

Shortest path between two given nodes.

Only works if all weights are positive.

##dijikstra complexity

Time worst case on a dense graph: $O(|V|^2)$.

In the worst case we have a dense graph and we must visit all the nodes giving:

- `FOR_VERTEX`: for each vertex ($|V|$):

    - MARK_VISITED: mark vertex as visited.

    - `FOR_NEIGHBOUR`: for each neighbour ($|V|$ for a dense graph):

        - UPDATE_WEIGHTS: update the weights of that neighbour

    - FIND_MIN: find the minimum adjacent element to determine the next vertex

Lets consider two data structure possibilities for storing node distances and if it was visited or not:

- unordered array
- min heap

###unordered array

Vertexes and their distances are stored in an array ordered by their index.

- `MARK_VISITED` is done in $O(1)$: just set the corresponding array element visited field to true.
- `UPDATE_WEIGHTS` can be done in time $O(1)$ if the vertexes are on an unordered array.
- `FIND_MIN` takes $O(V)$

Total time:

$$
    FOR_VERTEX * ( MARK_VISITED + ( FOR_NEIGHBOUR * UPDATE_WEIGHTS    ) + FIND_MIN    ) =
    V *          ( 1            + ( V             * 1                 ) + V           ) =
    V^2
$$

operations.

###min heap

TODO get this right

- `MARK_VISITED` means that we have to remove the root element from the min heap which takes $lg$ for any type of heap known.
- `UPDATE_WEIGHTS` takes $O(log(V))$ since we have to reorder the ordered list after each insertion.
- `FIND_MIN` takes $O(1)$

Therefore we have:

$$
    FOR_VERTEX * ( MARK_VISITED + ( ( FOR_NEIGHBOUR * UPDATE_WEIGHTS ) + FIND_MIN ) =
    V *          ( log(V)       + ( ( V             * 1              ) + 1        ) =
$$

TODO use alignat here

---

We should therefore use the unordered data structure if the graph is dense.

However, if the graph is known to be sparse enough, ($degree(v) < V/log(V)$),
then the ordered approch starts being better.

#A star

aka A*

Does the same as Dijikstra, but supposes that extra knowledge is known about the graph.

That extra knowledge is an estimative $h$ of distance between the current node and the target
such as the straight line or manhattan distance.

The algorithm then first explores nodes with lowest: $current distance + h(next node)$

Good tutorial:

- <http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html>

Let $h(x)$ be the estimative.

- $h(x)$ is alwasys smaller than the actual distance to goal: convergence guaranteed.

- $h(x) = 0$: same as Dijikstra

- $h(x)$ is the exact distance to destination: only the correct path is explored.
