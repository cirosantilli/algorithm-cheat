# Heap

Concept: <http://en.wikipedia.org/wiki/Heap_%28data_structure%29>

Operations and complexities for each type: <http://en.wikipedia.org/wiki/Heap_%28data_structure%29#Comparison_of_theoretic_bounds_for_variants>

Efficient concrete data structure to implement a priority queue abstract structure.

## Operations

- `find-max`: find the maximum item of a max-heap
- `create-heap`: create an empty heap
- `heapify`: create a heap out of given array of elements
- `delete-max`: removing the root node of a max-heap, respectively
- `increase-key`: updating a key within a max-heap, respectively
- `insert`: adding a new key to the heap
- `merge`: joining two heaps to form a valid new heap containing all the elements of both

## Types

### Binary heap

<http://en.wikipedia.org/wiki/Binary_heap>

The main operation that the `heap` does better than a BST is `find-max`. TODO vs a modified binary search tree that keeps track of the maximum and minimum on every operation that might change it? <http://stackoverflow.com/questions/6147242/heap-vs-binary-search-tree-bst/27074221#27074221>, <http://stackoverflow.com/questions/7878622/can-we-use-binary-search-tree-to-simulate-heap-operation>, <http://cs.stackexchange.com/questions/27860/whats-the-difference-between-a-binary-search-tree-and-a-binary-heap> Advantages I've seen so far:

- the heap is that it can be implemented on top of an array, which saves memory as you don't keep pointers, only the raw data
- heap insert is `1` in average

`increase-key` requires an extra index, either a map or an array: <http://stackoverflow.com/questions/17009056/how-to-implement-ologn-decrease-key-operation-for-min-heap-based-priority-queu>

#### Binary heap vs binary tree

<http://stackoverflow.com/a/29548834/895245>

## Array implementation

The advantage of doing so is that it uses less space than objects and pointers (no need for the pointers)

It is possible to do so because:

-   the parent of $i$ is at $floor(i/2)$

-   the children of $i$ are at $floor(i/2)$

-   all operations come down to switching elements two by two.

    There is no operation which involves insertion at an arbitrary point of the array, which would require the costly operation of shifting all elements to the right once.

## Binary

Simplest implementation. Good in practice.

Operation explanation: <http://en.wikipedia.org/wiki/Binary_heap#Heap_operations>

For increase-key to work, a separate map of values to positions must be kept up to date after certain operations, and be accessible and kept up to date in time not larger than the corresponding operations.

Since all operations that modify / access the map are $O(log(n))$ for the binary heap, a simple balanced binary tree will do (also has $O(log(n))$).

## Pairing

<http://en.wikipedia.org/wiki/Pairing_heap>

## Fibonacci

1987.

Best in practice for large enough problems. Theoretically good amortized times.

The only operation that has $log(n)$ amortized time is deleting the root, the others are $O(1)$.

## Brodal

1996.

<http://en.wikipedia.org/wiki/Brodal_queue>

Best theoretical asymptotic worst cases. Not useful in practice.
