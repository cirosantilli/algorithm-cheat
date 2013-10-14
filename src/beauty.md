The beauty of computer science lies mainly on:

- its huge usefulness

- a few theorethical questions with deep implications

- the endless race for *the* ultimate algorithm that solves each problem

#sources

- <https://en.wikipedia.org/wiki/List_of_algorithms>

    Large list of important algorithms ranged by category.

    Good place to look for cool algorithms.

#theorethical questions

##p vs np

<https://en.wikipedia.org/wiki/P_versus_NP_problem>

##undecidability

<http://en.wikipedia.org/wiki/Undecidable_problem>

##fptas

1/0 knapasack can be solved in polynomial time in $n$ and $\epsilon$
if solutions that are $1 - \epsion$ of the optimum are acceptable!

<http://en.wikipedia.org/wiki/FPTAS>

#algorithms

This is a list of cool problems and algorithms that solve those problems.

It is cool to understand how the following calculations can be implemented:

- factorial

- fibonacci series.

    Specially interesting to look at efficient different implementations and their efficienty:

    - simple recursive:               $O(2^n)$ time!

    - dynamic programming with array: $O(n)$ time, $O(n)$ memory.

    - dynamic programming storing border only: $O(n)$ time, $O(1)$ memory.

- mcd, mcm

- primality testing: given a number, is it prime or not?

    For a long time it was an open question if a polynomial algorithm existed.

    Note that the naive algorithm of trying division by every number below $\sqrt(n)$ is polynomial on the value of $n$,
    but *not* on the number of digits of the input, which is what is considered in complexity analysis.

    The question was solved positively in 2002 by the [AKS primality tesst](https://en.wikipedia.org/wiki/AKS_primality_test).
    Before AKS, there were many algorithms which were either probabilistic, or dependend on the truth of unproven conjectures,
    at the time of their proposal, such as the Miller test which depends on the generalized Riemann hypothesis.

    Many variants of AKS were created, and one of them is known to run in $O(log^6(n))$.

- combinatorial optimiazation and satisfiability:

    - knapasack

    - [coin problem](http://en.wikipedia.org/wiki/Coin_problem)

        A monetary system has 3 types of coins: 3, 5 and 7. What is the largest ammount that cannot be attained?

        NP-complete in the number of types of coins.

    - [change making problem](http://en.wikipedia.org/wiki/Change-making_problem)

        What is the smallest number of coins needed to make a given value exactly?

        NP-complete in the number of types of coins.

        Belongs to the knapsack family.

- sorting

    Compare all the sorting algorithms! Which is the *best*?

- heaps: the search for the ultimate heap:
    <http://en.wikipedia.org/wiki/Heap_%28data_structure%29#Comparison_of_theoretic_bounds_for_variants>

- graph algorithms:

    - bfs vs dfs. See queue vs stack duality of non recursive implementation.

    - single source shortest path:

        - [dijikstra](http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) 1959 $O(|E| + |V| log |V|)$. Positive weights only.

        - [A*](http://en.wikipedia.org/wiki/A*_search_algorithm) 1968.
            Heuristic improvement over dijikstra if a distance function exists.

        - [bellman-ford](http://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 1965.
            $O(|V|^2 log |V|)$, but also accepts negative weights.

    - all pairs shortest path:

        - [floyd warshall](http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) 1959 / 1962.
            $O(|V|^3)$, negative weights ok.

        - [johnson's algorithm](http://en.wikipedia.org/wiki/Johnson%27s_algorithm) 1977
            $O( |V|^2 log |V| + |V||E|)$, therefore better than floyd marchal for sparse graphs.
            Negative weights ok.

    - TSP

    - [four color theorem](http://en.wikipedia.org/wiki/Four-color_theorem)

        You can color a map with 4 colors in a way that no two countries share a border with same color.

        Graph statement: every planar graph can be colored in a way that no two neighbours have the same color.

        Conjectured in 1852, proven in 1976.

        Proof uses a computer to check each 1936 base cases, first of its type.

        Proof for the 5 color case much easier and completed in 1890.

        Simple to state, hard to prove.

        Complexity of finding a coloring: $O(n^2)$.

- dynamic programming

    - [maximum subarray problem](https://en.wikipedia.org/wiki/Maximum_subarray_problem)

        Solvable in $O(n)$.

    - [change-making problem](https://en.wikipedia.org/wiki/Change-making_problem)

        Solvable in $O(n log n)$.

- [tower of hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)

    Cool graph visualiation that becomes a Sierpinski triangle, and which make crystal clear:

    - unicity
    - length of the optimal path: $2^n - 1$. This path is simple to compute.

    Variations are also interesting:

    - go from any initial configuration to any final configuration.

        - the graph shows that there can be only either 1 or 2 optimal paths.

        - the original problem of moving all pegs from one configuration to another is the problem that takes the longest
            time possible.

            This time is also attained by any other problem on the opposite side of the sierpinski triangle.

            Any starting position on the interior will lead to shortesr optimal paths to anywhere.

        - there is an explicit formula by Hinz and Chan Hat-Tung for the average optimal solution length
            if initial and states are chosen at random which is assymptotically: $466/885 * 2^n - 1/3 + o(1)$

    - any increase the number of pegs.

        For 4 pegs, the problem is known as *Reve's puzzle*.

        It is possible to do a brute-force solution by representing the problem as a graph and doing BFS,
        but this is of course exponential in memory and time.

        There is no polynomial algorithm proven to compute the solution although the Frame-Stewart algorithm
        is conjectured to do so.

        As a consequence, exact bounds for a given number of disks and pegs are unknown.

- pseudo random number generation.

- branch and bound with relaxation.

    Relaxation means to suppose the problem can have fracitonal solutions.

    It becomes then a continuous linear programming problem, and can therefore be solved in polynomial time.

    We know that the actual solution cannot be better than the relaxed one,
    since the relaxed solution has many more possibilities, so we can bound what is the best possible solution.

    This allows for more efficient cutting.

- [karp's 21 NP complete problems](http://en.wikipedia.org/wiki/Karp%27s_21_NP-complete_problems)

    Very famous list of NP complete problems you should know about.

##integer multiplication

- unknown sup of lower bounds

- naive $n^2$

- karatsuba

    <http://en.wikipedia.org/wiki/Karatsuba_algorithm>

    multiplication in $O(n^{\log_{2}3})$

- tom-cook

    generalization of karatsuba

    <http://en.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication>

    algorithm family, hard to analyse, Toom-3 does $O(n^{\log_{3}5})$, about
    $O(n^{1.465})$

- schonhage–strassen

    $O(log n log log n)$

    FFT based!

##matrix multiplication

<http://en.wikipedia.org/wiki/Matrix_multiplication#Algorithms_for_efficient_matrix_multiplication>

Is there an $O(n^2)$ matrix multiplication algorithm? If not, how fast can we get?

This is pratically important because matrix mulitplications are done millions and millions of times
to approximate solutions to physical problems.

Naive school algorithm: $O(n^3)$.

First improvement: [1969 strassen](http://en.wikipedia.org/wiki/Strassen_algorithm). Easy to understand,
and better in practice for large enough matrices.

Current best: [1987 volker-strassen](http://en.wikipedia.org/wiki/Coppersmith%E2%80%93Winograd_algorithm).
More complicated and not yet useful on practical matrix sizes found on current problems.

##numerical analysis

These algorithms / problems may require analysis background to understand.

They are fun and important to implement solutions using computers.

- exponential

- integration and derivation

- taylor series

- f(x) = 0
    - divide by two
    - newtons method

- matrices

- FFT

- eq difs: ordinary/partial

- finite elements
