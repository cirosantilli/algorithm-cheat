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

-   <https://en.wikipedia.org/wiki/Partition_problem>: make teams of equal strength, use two piles of books to make a horizontal table

Computer graphics:

-  <https://en.wikipedia.org/wiki/Bresenham's_line_algorithm>

Ranking and search algorithms:

-   <http://www.quora.com/What-algorithm-does-IMDB-use-for-ranking-the-movies-on-its-site>

    <http://math.stackexchange.com/questions/169032/understanding-the-imdb-weighted-rating-function-for-usage-on-my-own-website>

-   <http://amix.dk/blog/post/19574> how Hacker News ranking algorithm works

    <http://amix.dk/blog/post/19588> how Reddit ranking algorithm works. Wilson score interval.

    <http://www.evanmiller.org/statistical-formulas-for-programmers.html>

-   TODO: Sort search results which have some sort of rating, e.g. GitHub "best match" search for repositories, which have stars.

-   TODO: Sort search results with multiple fields of different importance. E.g.: title and summary.

-   <http://www.quora.com/Recommendation-Systems/How-do-ranking-algorithms-eg-Amazon-Tripadvisor-work>

-   <https://en.wikipedia.org/wiki/Bag-of-words_model>

-   <https://en.wikipedia.org/wiki/Okapi_BM25>

Error correction:

-   <https://en.wikipedia.org/wiki/Cyclic_redundancy_check> CRC

-   <https://en.wikipedia.org/wiki/Hamming%287,4%29>

    Interesting, it has a matrix representation!

    TODO: what does it mean that it is linear?

-   As mentioned at <https://en.wikipedia.org/wiki/Forward_error_correction>, error correction is much more useful for multicast, where it would be impractical for all receivers to request a correction.

    TODO vs Hamming code? <https://en.wikipedia.org/wiki/Cyclic_code#Hamming_code> Many Hamming codes are also CRC. TODO: is there any advantage for those that are not?

-   <https://en.wikipedia.org/wiki/Reed%E2%80%93Solomon_error_correction> Used in most modern optic and magnetic media.

-   <https://en.wikipedia.org/wiki/Erasure_code> Some error checking can also deal with erasure.

-   <https://en.wikipedia.org/wiki/Cache_algorithms>, LRU with heap

-   geometric algorithms

    - <https://en.wikipedia.org/wiki/Closest_pair_of_points_problem>, 2D Euclidean can be done in O(n log n)

    - <https://en.wikipedia.org/wiki/Nearest_neighbor_search#Methods> Euclidean.
