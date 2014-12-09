# Merge sort

Worst: $n log(n)$ time $n$ space

Average: same.

Principle:

- merging two ordered lists of size `n` can be done in `O(n)` time `O(n)` memory.
- start with lists of size 1 (always ordered), of items side by side, then 2, then 4, etc. `log(n)` times.

## Global view

The input comes into an array:

    input: 4 2 1 3

We first divide it in 1 sized chunks:

    4 | 2 | 1 | 3

The first step is to merge:

-   two sorted lists: one containing only `2` and the other only `4`

        4 | 2 | 1 3
        ^   ^

    This gives:

        2 | 4 | 1 3
        ^   ^

-   two sorted lists: one containing only `1` and the other only `3`

        2 4 | 1 | 3
              ^   ^

    Since they are already sorted, this gives:

        2 4 | 1 | 3
              ^   ^

Keep in mind that an array with a single element is always sorted.

Next we split things into 2 sized chunks:

    2 4 | 1 3

And we merge two sorted lists `2 4` and `1 3` with $n=2$, which gives:

    1 2 3 4

If there were still more elements, we would take sizes 4, 8 and so on.

In [another section](merge-step) we will go into detail on how to do the merge of two sorted arrays efficiently.

## Merge step

The merge step takes two *ordered* arrays of same size and merges them.

It is the key for the efficiency of this algorithm.

Let's merge the two following ordered arrays: `2 4` and `1 3`, both of size `n = 2`.

They are both on a single input array side by side:

    input: 2 4 | 1 3

The `|` is just to ease the visualization: it does not exist on the array.

First make a copy of the input (`O(n)` memory):

    input:  2 4 | 1 3

    output: 2 4   1 3

Now point to their elements with indexes `k`, `i` and `j` as:

    input:  2 4 | 1 3
            ^     ^
            i     j

    output: 2 4   1 3
            ^
            k

$i$ points to the first of the first list, and $j$ to the fist of the second list.

$j$ points to the first of the output.

Compare values of $A[i]$ and $A[j]$.

Put the smallest one into $A[k]$:

    input:  2 4 | 1 3
            ^     ^
            i     j

    output: 1 4   1 3
            ^
            k

So the smallest was 1 (the other was 2).

Move $k$, and the smallest of $i$ and $j$ forward:

    input:  2 4 | 1 3
            ^       ^
            i       j

    output: 1 4   1 3
              ^
              k

$k$ moved from 1 to 4, $j$ moved from 1 to 3 because it was the smallest and not $i$.

This is the end of the step.

In total we did:

- one comparison: $A[i]$ and $A[j]$
- one value copy: $A[i]$ or $A[j]$ to $A[k]$
- two increments: $i$ and $j$

Repeat step:

    input:  2 4 | 1 3
              ^     ^
              i     j

    output: 1 2   1 3
                  ^
                  k

Repeat step:


    input:  2 4 | 1 3
              ^       ^
              i       j

    output: 1 2   3 3
                    ^
                    k

Oops, $j$ fell out.

Last rule: if one of them falls out, it equals infinity.

We can now just copy the remaining elements of the other side into the output
with an efficient `memcpy` (in this case a single element `4`):

    input:  2 4 | 1 3
                ^     ^
                i     j

    output: 1 2   3 4
                      ^
                      k

Opps, $k$ fell out. This means that the merge has ended.

As we can see, the output contains the elements of both inputs and is ordered.

We took each step exactly $2n$ times, where $n$ is the length of each half,
because:

- $k$ increases once per step
- the step ends when $k$ falls out of the output.

Therefore each merge step of two arrays of size $n$ takes $O(n)$ steps.

## Complexity recursive analysis

Let $S(n)$ be the number of steps for size $n$.

We have:

$$S(n) = 2*S(n/2) + C*n$$

We can then verify that the solution has the form:

$$A*n*log(n)$$

where:

$$A = TODO$$

## Complexity non recursive

Let $N$ be the number of elements.

We need to work with powers of 2, so let $2^m$ be the first power of two larger than $N$.

For a simple analysis, we can just fill all values between $A[N + 1]$ and $2^m$ with infinities.

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
where we recall that C was the cost of:

- one comparison
- one value copy
- two increments

The memory worst case was all on the last merge, which required merging $N/2$ arrays,
so we actually made a copy of th entire original array.
