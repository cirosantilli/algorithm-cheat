# Topological sort TODO

Linearize a digraph in a way that related nodes keep the order.

Not unique.

Exists iff there is no cycle, i.e., if the graph is a Directed acyclic graph (DAG) <https://en.wikipedia.org/wiki/Directed_acyclic_graph>

Applications:

- `git log` must somehow linearize the commit tree to show it in the terminal (cannot be cyclic because would require SHA conflict: TODO check). In normal repositories it is a DAG. Topological sort is the default option, the other major intuitive method being by timestamp.
