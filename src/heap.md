Concept: <http://en.wikipedia.org/wiki/Heap_%28data_structure%29>

Operations and complexities for each type:
<http://en.wikipedia.org/wiki/Heap_%28data_structure%29#Comparison_of_theoretic_bounds_for_variants>.

Efficient data structure for a priority queue.

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

#fibonacci

1987.

Best in practice for large enough problems. Theorethically good amortized times.

The only operation that has $log(n)$ amortized time is deleting the root, the others are $O(1)$.

#brodal

1996.

<http://en.wikipedia.org/wiki/Brodal_queue>

Best theorethical assymptotic worst cases. Not useful in practice.
