# TODO

Algorithms that could be included:

-   <http://stackoverflow.com/questions/2113795/quickest-way-to-find-missing-number-in-an-array-of-numbers>

    Find the missing number of an increasing sequence that has been mixed up.

    E.g., start with:

        1 2 3 4 5 6

    Mix up:

        6 3 5 4 2 1

    Remove an unknown number:

        6 5 4 2 1

    Which number was removed?

    Solution: sum up, use the sum formula, take difference.

-   <http://stackoverflow.com/questions/3492302/easy-interview-question-got-harder-given-numbers-1-100-find-the-missing-numbe>

    Same as above, but remove 2 numbers instead.

-   <http://stackoverflow.com/questions/1586858/find-the-smallest-integer-not-in-a-list>

    Find the smallest non-negative integer *not* in an unsorted array of length `N`.

    The array is stored in RAM.

    Application: generate unique IDs in a system where any ID can be removed.

    Solution intuition:

    - `N` is the largest possible value in case of an increasing sequence. This means that you can throw away any number larger than `N`.
    - if the array were sorted, it would be easy.
    - there are non-comparison sorting algorithms for integers in a fixed range that perform $O(N)$ time $O(1)$ memory.

    Solution: 2 passes, first try to put every number smaller than `N` in the array position with same value as the number. If already occupied by another number, do the same for the other number. Throw away anything larger than `N`.

-   <https://en.wikipedia.org/wiki/Out-of-core_algorithm>. We currently have `tac`. Find more.

-   <http://en.wikipedia.org/wiki/Partition_problem>. Partition a multiset into two sub-multisets such that the sum of each sub-multiset is equal. NP-complete.

    Many not have a solution, which leads to the optimization version: minimize the difference. NP-hard.

-   <http://en.wikipedia.org/wiki/Stable_marriage_problem>

-   <http://en.wikipedia.org/wiki/National_Resident_Matching_Program#Matching_algorithm>

-   <http://en.wikipedia.org/wiki/Stable_roommates_problem>

Some NP-complete ones:

-   <http://en.wikipedia.org/wiki/Karp%27s_21_NP-complete_problems>

-   <http://en.wikipedia.org/wiki/Vertex_cover>
