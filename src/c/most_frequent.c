/*
Find the most frequent number in an array.

The maximum size of each element is bounded and fits into memory,
so an array solution is possible. Otherwise, we'd need a map.
*/

#include "common.h"

int solution0(int M, int A[], int N) {
    int *count = malloc((M + 1) * sizeof(int));
    int i, *ip;
    int index = 0;
    int maxOccurence = 0;
    for (i = 0; i <= M; i++)
        count[i] = 0;
    for (i = 0; i < N; i++) {
        ip = &count[A[i]];
        if (*ip == maxOccurence) {
            maxOccurence++;
            index = i;
        }
        (*ip)++;
    }
    free(count);
    return A[index];
}


/* Weird solution that counts one specially. */
int solution1(int M, int A[], int N) {
    int *count = malloc((M + 1) * sizeof(int));
    int i;
    for (i = 0; i <= M; i++)
        count[i] = 0;
    int maxOccurence = 1;
    int index = 0;
    for (i = 0; i < N; i++) {
        if (count[A[i]] > 0) {
            int tmp = count[A[i]] + 1;
            if (tmp > maxOccurence) {
                maxOccurence = tmp;
                index = i;
            }
            count[A[i]] = tmp;
        } else {
            count[A[i]] = 1;
        }
    } free(count);
    return A[index];
}

typedef int t;

void assert_solution(
        t *A,
        size_t N,
        t M,
        t *valid_outputs,
        size_t valid_outputs_size) {
    int output = solution0(M, A, N);
    size_t i;
    for (i = 0; i < valid_outputs_size; ++i)
        if (output == valid_outputs[i])
            return;
    assert(false);
}

int main(void) {
    /* TODO loop over all implementations. */

    assert_solution((t[]){1}, 1, 1, (t[]){1}, 1);

    /* Two possibilities. */
    assert_solution((t[]){1, 2, 3, 3, 1, 3, 1}, 7, 3, (t[]){1, 3}, 2);

    /* Should fail. */
    /*assert_solution((t[]){1, 2, 3, 3, 1, 3, 1}, 7, 3, (t[]){0, 2}, 2);*/

    assert_solution((t[]){1, 2, 3, 3, 1, 3, 3}, 7, 3, (t[]){3}, 1);

    return EXIT_SUCCESS;
}
