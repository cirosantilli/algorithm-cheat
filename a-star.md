# A star TODO

# A* algorithm

Does the same as Dijkstra, but supposes that extra knowledge is known about the graph.

That extra knowledge is an estimative $h$ of distance between the current node and the target such as the straight line or manhattan distance.

The algorithm then first explores nodes with lowest: $current distance + h(next node)$

Good tutorial:

- <http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html>

Let $h(x)$ be the estimative.

- $h(x)$ is always smaller than the actual distance to goal: convergence guaranteed.
- $h(x) = 0$: same as Dijkstra
- $h(x)$ is the exact distance to destination: only the correct path is explored.
