Concept: <http://en.wikipedia.org/wiki/Heap_%28data_structure%29>

Operations and complexities for each type:
<http://en.wikipedia.org/wiki/Heap_%28data_structure%29#Comparison_of_theoretic_bounds_for_variants>.

Efficient concrete data structure to implement a priority queue abstract structure.

#operations

Efficient operations that can be done on a heap are:

- create-heap: create an empty heap.
- heapify: create a heap out of given array of elements.
- find-max or find-min: find the maximum item of a max-heap or a minimum item of a min-heap, respectively (aka, peek).
- delete-max or delete-min: removing the root node of a max- or min-heap, respectively.
- increase-key or decrease-key: updating a key within a max- or min-heap, respectively.
- insert: adding a new key to the heap.
- merge: joining two heaps to form a valid new heap containing all the elements of both.

#array implementation

The advantage of doing so is that it uses less space than objects and pointers (no need for the pointers)

It is possible to do so because:

- the parent of $i$ is at $floor(i/2)$

- the children of $i$ are at $floor(i/2)$

- all operations come down to switching elements two by two.

    There is no operation which involves insertion at an arbritary point of the array,
    which would require the costly operaiton of shifting all elements to the right once.

#binary

Simplest implementation. Good in practice.

Operation explanation: <http://en.wikipedia.org/wiki/Binary_heap#Heap_operations>

For increase-key to work, a separate map of values to positions must be kept up to date after certain operations,
and be accessible and kept up to date in time not larger than the corresponding operations.

Since all operations that modify / access the map are $O(log(n))$ for the binary heap,
a simple balanced binary tree will do (also has $O(log(n))$).

#fibonacci

1987.

Best in practice for large enough problems. Theorethically good amortized times.

The only operation that has $log(n)$ amortized time is deleting the root, the others are $O(1)$.

#brodal

1996.

<http://en.wikipedia.org/wiki/Brodal_queue>

Best theorethical assymptotic worst cases. Not useful in practice.
