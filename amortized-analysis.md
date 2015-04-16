# Amortized analysis

Considers the average operation time on possible sequences of operations.

Sources:

<https://en.wikipedia.org/wiki/Amortized_analysis>

[cormen09][] chapter 17 "Amortized Analysis".

Famous examples:

-   array backed heap. Worst case insert and delete is linear as it may require a copy operation to increase capacity.

    But those operations can only happen exponentially little if we only do additions, so the amortized is still constant.

    Note how the operation choice matters: if we allow insertion and deletion, then a sequence of insertion / deletion at the discontinuity could still have linear time.

-   <https://en.wikipedia.org/wiki/Fibonacci_heap> analysis, which is famously `O(1)` amortized, which is stronger than the `O(1)` average of binary heaps.
