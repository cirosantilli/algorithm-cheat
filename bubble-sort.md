# Bubble sort

Very slow.

Very simple. Shortest code.

Worst: $n^2$ time (extremely rare) $1$ space (in place)

Average: $n^2$.

Bubble.

- quick. Worst: $n^2$ time, $n$ space.

## Bubble visualization

Start with:


    4 2 1 3

We compare two by two and exchange if needed:

    4 2 1 3
    ^ ^

4 is larger than 2, so exchange, giving:

    2 4 1 3
    ^ ^

Move forward:

    2 4 1 3
      ^ ^

4 is larger than 1, so exchange, giving:

    2 1 4 3
      ^ ^

Move forward:

    2 1 4 3
        ^ ^

4 is larger than 3, so exchange, giving:

    2 1 3 4
        ^ ^

We reached the end. Restart:

    2 1 3 4
    ^ ^

Then:

    1 2 3 4
    ^ ^

    1 2 3 4
      ^ ^

2 is smaller than 3, don't exchange.

    1 2 3 4
        ^ ^

We reached the end, restart:

    1 2 3 4
    ^ ^

    1 2 3 4
      ^ ^

    1 2 3 4
        ^ ^

We made no exchanges on the latest pass, so we are done. As we can see, the list is sorted.

## Correctness

TODO

## Complexity

Input of length $n$, un upper limit for the worst possible case is $n^2$ because TODO.

But then for each $n$ we can generate a case which takes $n^2$ TODO

Therefore the w4 2 1 3 worst case complexity must be $n^2$.
