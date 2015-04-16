# Dijkstra

<http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm>

Find the shortest path between two given nodes.

Only works if all weights are positive. If negative weights are possible, consider using the [Bellman-Ford algorithm](http://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm).

## Dijkstra complexity

Time worst case: $O(|E| + |V| log |V|)$, so $O(|V|^2)$ on a dense graph.

In the worst case we have a dense graph and we must visit all the nodes giving:

-   `FOR_VERTEX`: for each vertex ($|V|$):

    -   `MARK_VISITED`: mark vertex as visited.

    -   `FOR_NEIGHBOUR`: for each neighbour: $|O(\sqrt(|E|))|$, $|V|$ for a dense graph.

        - `UPDATE_WEIGHT`: update the weights of that neighbour

    -   `FIND_MIN`: find the minimum adjacent element to determine the next vertex

Lets consider two data structure possibilities for storing node distances and if it was visited or not:

- unordered array
- min heap

### Unordered array

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

### Min heap

We order the vertexes on a min heap that takes the distance into account.

The complexity will depend on the type of min heap used. We consider there the two most common and efficient min heaps for practical data sizes:

- binary heap
- Fibonacci heap

TODO get this right

-   `MARK_VISITED`: means that we have to remove the root element from the min heap:

    - Binary heap:    `log`
    - Fibonacci heap: `n` worst case, `log` amortized

-   `UPDATE_WEIGHT`:  this critical operation depends on the type of min heap used.

    - Binary heap:    `log`
    - Fibonacci heap: `log` worst case, `1`

-   `FIND_MIN`: always $O(1)$ since we are using heaps

Therefore for the binary heap:

$$
    FOR_VERTEX * ( MARK_VISITED + ( ( FOR_NEIGHBOUR * UPDATE_WEIGHTS ) + FIND_MIN ) =
    V *          ( log(V)       + ( ( V             * log V          ) + 1        ) =
    V^2 log(V)
$$

and for Fibonacci amortized time:

$$
    FOR_VERTEX * ( MARK_VISITED + ( ( FOR_NEIGHBOUR * UPDATE_WEIGHTS ) + FIND_MIN ) =
    V *          ( log(V)       + ( ( V             * 1              ) + 1        ) =
    V^2
$$

## Choice of data structure

The final choice of the data structure will depend on the expected density of the graph:

-   if the graph is expected to be dense, use an unordered array, as it has the best worst time for that case, while a Fibonacci heap offers only

-   if the graph is known to be sparse, $degree(v) <<< V/log(V)$, then the heap approach starts being better.

-   If amortized time can be taken into account and it is not clear if the graph is dense or not, the Fibonacci Heap implementation is the best option, as it:

    - works as well as the unordered array implementation for dense graphs
    - works better if the graph is not dense (often the case).

