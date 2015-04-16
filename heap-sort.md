# Heap sort

Convert to a heap, then delete from the top until the heap is over.

Time: $O(n log(n))$ worst and average. Creating the heap is $O(n)$, deleting the top is $O(log(n))$, and since we delete $n$ times we have $n log(n)$.

Space: $O(1)$ worst (in place). To do it:

- swap the top element with the smallest one
- reduce the heap size by 1
- sift down the new top element, currently the smallest, to restore the heap
