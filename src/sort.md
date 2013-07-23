Sorting algorithms.

To understand them, see how they work step by step on examples.

#sources

- <https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms>

    Compare them all

#buble

Very slow.

Very simple.

Worst: $n^2$ time (extermelly rare) $1$ space (in place)

Average: $n^2$.

Bubble.

- quick. Worst: $n^2$ time, $n$ space.

##bubble visualization

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

We did nothing on this lastr run (since we returned to the first case, so we are done.

##correctness

TODO

##complexity

Input of length $n$, un upper limit for the worst possible case is $n^2$ because TODO.

But then for each $n$ we can generate a case which takes $n^2$ TODO

Therefore the w4 2 1 3orst case complexity must be $n^2$.

#insert

#merge

Worst: $n log(n)$ time $n$ space

Average: same.

Principle:

- merging two ordered lists os size `n` can be done in `O(n)` time `O(n)` memory.
- start with lists of size 1 (always ordered), of items side by side, then 2, then 4, etc. `log(n)` times.

##recursion step

The input comes into an array:

    input: 4 2 1 3

We first divide it in 1 sized chunks:

    4 | 2 | 1 | 3

The first step is to merge:

- two sorted lists: one containing only `2` and the other only `4`

        4 | 2 | 1 | 3
        ^   ^

    This gives:

        2 | 4 | 1 | 3
        ^   ^

- two sorted lists: one containing only `1` and the other only `3`

        2 | 4 | 1 | 3
                ^   ^

    Since they are already sorted, this gives:

        2 | 4 | 1 | 3
                ^   ^

Keep in mind that an array with a single element is always sorted.

Next we split things into 2 sized chunks:

    2 4 | 1 3

And we merge:

- two sorted lists `2 4` and `1 3` with $n=2$, which gives:

    1 2 3 4

If there were still more elements, we would take sizes 4, 8 and so on.

In [another section](merge-step) we will go into detail on how to do the merge of two sorted arrays efficiently.

##merge step

The merge step takes two *ordered* arrays of same size and merges them.

It is the key for the efficiency of this algorithm.

Let's merge the two following ordered arrays: `2 4` and `1 3`, both os size `n = 2`.

They are both on a single input array side by side:

    input: 2 4 1 3

That will be our input.

First make a copy of the input (`O(n)` memory):

    input:  2 4 1 3

    output: 2 4 1 3

Now point to their elements with indexes `k`, `i` and `j` as:

    input:  2 4 1 3
            ^   ^
            i   j

    output: 2 4 1 3
            ^
            k

`i` points to the first of the first list, and `j` to the fist of the second list.

`j` points to the first of the output.

Compare values of `A_i` and `A_j`.

Put the smallest one into `A_k`:

    input:  1 4 1 3
            ^
            k

    output: 2 4 1 3
            ^   ^
            i   j

So the smallest was 1 (the owther was 2).

Move k, and the smallest of i and j forward:

    input:  2 4 1 3
            ^     ^
            i     j

    output: 1 4 1 3
              ^
              k

k moved from 1 to 4, j moved from 1 to 3 because it was the smallest and not i.

This is the end of the step.

In total we did:

- one comparison (`A[i]` and `A[j]`)
- one value copy
- two increments (i and j)

Repeat step:

    input:  2 4 1 3
              ^   ^
              i   j

    output: 1 2 1 3
                ^
                k

Repeat step:


    input:  2 4 1 3
              ^     ^
              i     j

    output:  1 2 3 3
                  ^
                  k


Ops, j fell out.

Last rule: if one of them falls out, it equals infinity.

We can now just copy the remaining elements of the other side into the output
with an efficient `memcpy` (in this case a single element `4`):

    input:  1 2 3 4
                    ^
                    k

    output: 2 4 1 3
              ^     ^
              i     j

Opps, k fell out. This means that the merge has ended.

We took each step exactly `2n` times, where `n` is the length of each half,
because:

- `k` increases once per step
- the step ends when `k` falls out of the output.

Therefore each merge step of two arrays of size `n` takes `O(n)` steps.

##complexity recursive analysis

Let `S(n)` be the number of steps for size `n`.

We have:

$S(n) = 2*S(n/2) + C*n$

We can then verify that the solution has the form:

$A*n*log(n)$

where:

$A = TODO$

##complexity non recursive

Let $N$ be the number of elements.

We need to work with powers of 2, so let $2^m$ be the first power of two larger than $N$.

For a simple analysis, we can just fill all values between $A[N + 1] and $2^m$ with infinities.

We are doing:

- $N/2$ merges with $n = 1$
- $N/4$ merges with $n = 2$
- $N/8$ merges with $n = 4$
- ...
- $N/2^{m+1}$ merges with $n = 2^m$

Since each merge of size $n$ takes $C*n$ operations, we have:

- $N/2$ times $Cn$ operations
- $N/4$ times $2*C*n$ operations
- $N/8$ times $4*C*n$ operations
- ...
- $N/2^{m+1}$ times $n = 2^m$

which makes a total of:

- $C*N/2$ operations
- $C*N/2$ operations
- ...
- $C*N/2$ operations

m times.

But since $2^m >= N$, we have in the worst case: $D*N*log(N)$, with $D = C/2$,
where C was the cost of:

- one comparison (`A[i]` and `A[j]`)
- one value copy
- two increments (i and j)

The memory worst case was all on the last merge, which required merging $N/2$ arrays,
so we actually made a copy of th entire original array.

#quick

Worst: $n^2$ time (extermelly rare) TODO space (in place)

Average: $log(n)$ time.

Even if it is quadratic worst time,
it is still quite used in practice because of $log(n)$ average and low memory usage,
and because it has good cache reutilization.

[Visualization](http://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

##visualization

    7 2 3 6 1 8 3

    7 2 3 6 1 8 3

#heap
