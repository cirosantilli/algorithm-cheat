# RB-tree TODO

# Red black tree

Balanced binary search tree.

Red black tree are binary search trees that support element query, insertion and deletion in $log(n)$ time.

All that is needed is to store one extra bit per node: red or black.

It must have the following properties:

-   A node is either red or black.

-   The root is black.

-   All leaves (NIL) are black.

-   Both children of every red node are black.

    Children of a black node can have any color.

-   Every simple path from a given node to any of its descendant leaves
    contains the same number of black nodes.

A leaf is not a node and a node is not a leaf in this context. Nodes contain the actual numbers that are being indexed, leafs don't contain any information, except indicating that there are no more nodes below.

Leafs in this context are also called sentinels.

Operations are $log(n)$ because the properties imply that the tree is balanced in the sense that the deepest leaf from a node can only be twice as deep as the shallowest one.

The key to using the tree is keeping it balanced after insertion or deletion.

Live Java applet demo: <http://www.ece.uc.edu/~franco/C321/html/RedBlack/>. Requires a bit too many clicks, but really cool.

TODO visualize insert
