# Insertion sort

<http://en.wikipedia.org/wiki/Insertion_sort>

In practice, used when the inputs are very small, e.g. < 10. Otherwise, a better worst case algorithm is chosen.

Create a new list (possibly in-place sublist), and insert elements into it so that it keeps sorted all the way

The complexities depend on the underlying data structures.

Arrays and linked lists: $O(N^2)$ time. Although the run time intuitively looks like $N log(N)$, it is not because:

- for arrays, you have to shift several elements to the right at each insertion
- for lists, the insertion is cheap, but you need linear time to find elements

However, if a more advanced data structure like a skip list is used, it is possible to have $N log(N)$.
