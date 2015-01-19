# Quicksort

$n^2$ time worst case. Extremely rare for random inputs, but happens exactly on the potentially common cases of sorted / reverse sorted inputs!

Average time: $log(n)$ time.

Space: $O(1)$ (in place).

Even if it is quadratic worst time,
it is still quite used in practice because of $log(n)$ average and low memory usage,
and because it has good cache reutilization.

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

## Worst case

The worst case happens when the input is either sorted or reverse sorted.

Although very rare for random inputs, almost sorted inputs may be common for certain applications.

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

OK, this should be enough to see what will happen.

We will do:

- $n$       moves on the first  run
- $n - 1$   moves on the second run
- ...
- $1$       move  on the last   run

Which gives:

$$n + (n - 1) + ... + 1 = n * (n + 1) / 2$$

moves, and therefore $O(n^2)$.

## Variants

### Dual pivot

Used in Java 7's `Arrays.sort`: <http://docs.oracle.com/javase/7/docs/api/java/util/Arrays.html#sort%28byte[]%29>

TODO
