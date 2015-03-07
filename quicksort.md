# Quicksort

-   Time:

    - $O(n^2)$ worst case time for an already sorted input input
    - $O(log(n))$ average (wort case is very rare)
    - $O(log(n))$ best for the traditional version on sorted input, $O(N)$ for the three-way version on constant input.

-   Unstable.

-   Extra memory: comes from the call stack:

    -   $O(n)$ worst on naive implementation for highly unbalanced tree of sorted input
    -   $O(lng(n))$ worst if right tail recursion optimized

Good cache reutilization: <http://cs.stackexchange.com/questions/3/why-is-quicksort-better-than-other-sorting-algorithms-in-practice>

## Visualization

Quick but imprecise view: [GIF visualization](http://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif).

Input array:

    8 2 7 1 3 5 6 4

Pointer setup:

    8 2 7 1 3 5 6 4
    ^             ^
    i             r
    j

Visualization: we will separate things into groups:

-   smaller or equal to $A[r]$

-   larger than $A[r]$

-   the pivot $A[r]$

              | 8 2 7 1 3 5 6 | 4
              | ^             | ^
              | i             | r
              | j             |
        small | large         | pivot


Where:

- $i$ is the first of the large side.
- $j$ is the current one we are checking now.
- $r$ is a recursive input of this step. It will move only between two steps. It starts at the rightmost element.

The rule is simple:

-   $A[j] > A[r]$?

    - Yes:  $j++$
    - No: exchange $A[i]$ and $A[j]$, $j++$, $i++$

$8 > 4$? Yes. $j++$:

          | 8 2 7 1 3 5 6 | 4
          | ^ ^           | ^
          | i j           | r
          |               |
    small | large         | pivot

$2 > 4$? No. Exchange $A[i]$ and $A[j]$:

          | 2 8 7 1 3 5 6 | 4
          | ^ ^           | ^
          | i j           | r
          |               |
    small | large         | pivot

$i++$ and $j++$:

        2 | 8 7 1 3 5 6 | 4
          | ^ ^         | ^
          | i j         | r
          |             |
    small | large       | pivot

$7 > 4$? Yes. $j++$:

        2 | 8 7 1 3 5 6 | 4
          | ^   ^       | ^
          | i   j       | r
          |             |
    small | large       | pivot

$1 > 4$? No. Exchange $A[i]$ and $A[j]$:

      2 1 | 7 8 3 5 6 | 4
          | ^   ^     | ^
          | i   j     | r
          |           |
    small | large     | pivot

$3 > 4$? No. Exchange $A[i]$ and $A[j]$:

      2 1 | 3 8 7 5 6 | 4
          | ^   ^     | ^
          | i   j     | r
          |           |
    small | large     | pivot

$i++$ and $j++$:

    2 1 3 | 8 7 5 6 | 4
          | ^   ^   | ^
          | i   j   | r
          |         |
    small | large   | pivot

And so on:

    2 1 3 | 8 7 5 6 | 4
          | ^     ^ | ^
          | i     j | r
          |         |
    small | large   | pivot

And:

    2 1 3 | 8 7 5 6 | 4
          | ^       | ^
          | i       | r
          |         | j
    small | large   | pivot

Oops: $j$ reached $r$. This means we are done, just exchange $A[r]$ and $A[i]$:

    2 1 3 4 | 7 5 6 8
          ^ |
          i |
            |
      small | large

Note how we effectively split things into two sides: one larger than $4$, the other smaller or equal to it.

Intuitively, why does it work? At each step, if we find a small number we throw it to the left, and the small side increases, eating that number up.

What to do next? Recurse down twice:

- from $0$ to $i - 1$
- from $i + 1$ to $N$

<!-- --!>

    2 1 3 | 4 | 7 5 6 8
    ^   ^ |   | ^     ^
    i   r |   | i     r
    j     |   | j

Showing only the left side:

    2 1 3
    ^   ^
    i   r
    j

$2 < 3$:

    2 1 3
      ^ ^
      j r
      i

$1 < 3$:

    2 1 3
        ^
        r
        i
        j

Exchange $A[r]$ and $A[i]$ ($3$ by itself, doing nothing):

    2 1 3
        ^
        r
        i
        j

Recurse again:

    2 1 | 3
    ^ ^ | ^
    i r | i
    j   | j
        | r

Left side:

    2 1
    ^ ^
    i r
    j

$2 < 1$:

    1 2
      ^
      r
      i
      j

Done. Recurse again:

    1 | 2
    ^ | ^
    r | r
    i | i
    j | j

Left side:

    1
    ^
    r
    i
    j

Oops, $i = j = r$ and there is a single element. This is the base case. Do nothing.

## Pseudo code

    void quicksort(int[] A, int left, int right)
        if left < right
            int middle = partition(array, left, right)
            quicksort(array, left, middle - 1)
            quicksort(array, middle + 1, right)

    int partition(int[] A, int left, int right)
        int i = left
        int j = left
        while j < right
            if A[j] > A[right]
                swap A[i], A[j]
                i++
            j++

You use `quicksort(A, 1, A.length())` to sort the entire array.

## Worst case

The worst case happens when the input is either sorted or reverse sorted.

Although very rare for random inputs, almost sorted inputs may be common for certain applications.

### Sorted input

Let's see how a sorted input yields worst time.

Initial input:

    1 2 3 | 4
    ^     | ^
    i     | r
    j     |

$1 < 4$:

    1 2 3 | 4
      ^   | ^
      i   | r
      j   |

$2 < 4$:

    1 2 3 | 4
        ^ | ^
        i | r
        j |

$3 < 4$:

    1 2 3 | 4
          | ^
          | r
          | i
          | j

Exchange, $4$ and $4$ and recurse.

Right side contains only $4$ so it is already sorted.

Left side gives:

    1 2 | 3
    ^   | ^
    i   | r
    j   |

The recurrence relation is:

$$T(n) = T(n - 1) + n$$

TODO can this be analysed with the master theorem?

Let's use induction.

We will do:

- $n$       moves on the first  run
- $n - 1$   moves on the second run
- ...
- $1$       move  on the last   run

Which gives:

$$n + (n - 1) + ... + 1 = n * (n + 1) / 2$$

moves, and therefore $O(n^2)$.

### Reverse sorted input

    8 7 6 5 4 3 2 1
    ^             ^
    i             r
    j

    8 7 6 5 4 3 2 1
    ^ ^           ^
    i j           r

    8 7 6 5 4 3 2 1
    ^   ^         ^
    i   j         r

Fast forward:

    8 7 6 5 4 3 2 1
    ^             ^
    i             r
                  j

    1 7 6 5 4 3 2 8
    ^             ^
    i             r
                  j

There is no left side. Recurse on right:

    7 6 5 4 3 2 8
    ^           ^
    i           r
    j

    7 6 5 4 3 2 8
    ^           ^
    i           r
    j

    7 6 5 4 3 2 8
      ^         ^
      i         r
      j

Fast forward:

    7 6 5 4 3 2 8
                ^
                r
                i
                j

There is no right side. Recurse on left:

    7 6 5 4 3 2
              ^
              r
              i
              j

Aha, another inverse sorted input, but unlike the sorted case, it came after two rounds. Same analysis as before.

### Repeated elements

In case all, or many of the elements are the same, the input is already sorted (and reverse sorted as well), so the running time is $n^2$.

But the three-way version does it linearly, which makes this implementation very popular as this may be a common case.

### Proof that this is the worst case

TODO. We need to use some formal property that encodes that fact that after any round, we get one step closer to the sorted output. Then count how many steps could happen.

## Best case

TODO. Find a family that always gets cut into half. Then optimality follows because of the theorem that says that $O(N log(N))$ is the best possible for comparison sort.

## Average case

TODO.

## Variants

### Three-way

This may however be a common case, so that a variant of quicksort exists that solves it.

The idea is simply to use an extra pointer when partitioning, so that the array will be split into three parts.

We then recurse quicksort on the left and right parts.

This problem has a famous artistic formulation: <http://en.wikipedia.org/wiki/Dutch_national_flag_problem>

TODO: I think the best case for this algorithm is $O(N)$ since if all elements are equal, a single pass is done.

### Tail recursion optimized

This reduces the extra memory from `O(N)` to `O(lg(N))`.

TODO implement. For this to work for the worst case, you must select the side with the fewest elements, and tail recurse the one with more elements.

    void quicksort(int[] A, int left, int right)
        if left < right
            int middle = partition(array, left, right)
            quicksort(array, left, middle - 1)
            quicksort(array, middle + 1, right)

    int partition(int[] A, int left, int right)
        int i = left
        int j = left
        while j < right
            if A[j] > A[right]
                swap A[i], A[j]
                i++
            j++

### Dual pivot

Used in Java 7's `Arrays.sort`: <http://docs.oracle.com/javase/7/docs/api/java/util/Arrays.html#sort%28byte[]%29>

TODO
