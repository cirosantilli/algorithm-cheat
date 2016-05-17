/*
Compare two arrays up to the delimiter 0.

Analogous to strcmp, or any other comparision where
we do not know the length of both arrays.

The delimiter is considered as the smallest possible element.
So a shorter prefix is smaller than a longer string that includes it.
*/

#include <assert.h>
#include <stdlib.h>

int cmp(int *a, int *b, int delimiter) {
    int b_delim;
    while (1) {
        b_delim = (*b == delimiter);
        if (*a == delimiter) {
            if (b_delim) {
                return 0;
            } else {
                return -1;
            }
        } else if (b_delim) {
            return 1;
        } else {
            if (*a < *b) {
                return -1;
            } else if (*a > *b) {
                return 1;
            }
        }
        a++;
        b++;
    }
}

int main(void) {
    const int d = 0;
    typedef int t[];

    /* Basic. */
    assert(cmp((t){1, 2, 3, d}, (t){1, 2, 3, d}, d) == 0);
    assert(cmp((t){1, 2, 3, d}, (t){1, 2, 4, d}, d)  < 0);
    assert(cmp((t){1, 2, 4, d}, (t){1, 2, 3, d}, d)  > 0);

    /* Different lengths. */
    assert(cmp((t){1, 2, d},    (t){1, 2, 3, d}, d) < 0);
    assert(cmp((t){1, 2, 3, d}, (t){1, 2, d},    d) > 0);

    /* Delimiter in the middle. */
    assert(cmp((t){1, d, 2}, (t){1, d, 3}, d) == 0);

    /* Empty. */
    assert(cmp((t){d}, (t){d}, d) == 0);

    return EXIT_SUCCESS;
}
