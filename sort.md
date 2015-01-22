# Sorting algorithms

To understand them, see how they work step by step on examples.

## Sources

-   <https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms>

    Compare them all

## Algorithm comparison

See this: <https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms>

It can be proven that the best a general algorithm can do is $O(n log(n))$ worst case time.

If extra information is known about the input, it is possible to reduce time worst case to $O(n)$.
For example, if the values are all integers between $0$ and $k$, and $k$ is $O(n)$, then
counting sort has $O(n)$ worst case.

There are many algorithms that sort in-place, thus achieving $O(1)$ extra memory
(excluding the input itself) worst case. This is the case for quicksort and heapsort,
but not for merge sort.

There are algorithms that achieve both optimal time and space at the same time such as heapsort,

Another parameter to take into account is stability.
Heapsort which achieves both $n log(n)$ worst case time and $O(1)$ space is not stable.

TODO is there a stable algorithm that achieves $n log(n)$ time $O(1)$ space *and* is stable?

In practice, considering cache performance and average cases, the following algorithms are very
common and can all give good results:

- quicksort: $O(n^2)$ worst case time but very rare
- mergesort
- heapsort

The following are less common:

- bubble sort. Very inefficient: used mostly for educational purposes

## Insert

TODO

## Heap

Convert to a heap, then sort the heap.

Time: $O(n log(n))$ worst.

Space: $O(1)$ worst (in place)

## Count

## Shuffle

Pseudo inverse of sorting.

## Shuffle

### Fisher Yates shuffle

<http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle>
