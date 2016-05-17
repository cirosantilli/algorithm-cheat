# BST

Binary search tree.

## Find next element

Given one element, find the next one.

- <http://stackoverflow.com/questions/22114903/how-to-find-the-next-in-order-successor-in-a-binary-tree>
- <https://www.quora.com/How-can-you-find-successors-and-predecessors-in-a-binary-search-tree-in-order>

Algorithm:

-   if there is a right node
    - go right once, then down left all the way
    - next element must be on right subtree, and the first thing there is left all the way
-   else
    - go up until you come up from the left or the root is reached
        - if the root is reached from the right, it's over
    - if you come up from the left, the parent must be the next thing to be visited
    - if you come up from the right, the parent is smaller and has already been visited. TODO clearer proof that this works.

## Delete element

Hard: <https://en.wikipedia.org/wiki/Binary_search_tree#Deletion>
