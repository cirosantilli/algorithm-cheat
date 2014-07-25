# Algorithms

Concepts that are useful to understanding algorithms in general.

Specific algorithms are not be given here.

## Sources

### Free sources

Lecture notes:

- <http://webdocs.cs.ualberta.ca/~holte/T26/top.realTop.html>
- <https://secweb.cs.odu.edu/~zeil/cs361/web/website/Directory/page/topics.html>

- hard algorithmic problems mostly without solution IIT course: <http://www.cse.iitb.ac.in/~aad/cs218/tutorial-1.txt>

### Non free sources

- [Skiena - Algorithm Design Manual 2ed][skiena]

[skiena]: http://www.amazon.com/Algorithm-Design-Manual-Steven-Skiena/dp/1848000693

- [Cormen - Introduction do Algorithms 2ed][cormen]

[cormen]: http://www.amazon.com/books/dp/0262033844

## Data structures

It is hard to separate data structures from algorithm analysis because:

Each data structure supports a different set of operations, and each operation has a different cost.

- to implement an algorithm, you will need a data structure
- to analyze operations of a data structure, you need to understand algorithms.

Some of the major classes of structures are:

-   linked list

-   hash map

-   graph

    - trees. Important subset of graphs.

## Algorithm analysis

You need to decide what algorithm is better than what: <http://en.wikipedia.org/wiki/Analysis_of_algorithms>

The consumption of the following resources must be analyzed:

- time
- memory

The following types of analysis give useful measures on how efficient an algorithm is in each of the resources:

- [worst case](#worst-case)
- [best case](#best-case)
- [average case](#average-case)
- [amortized](#amortized)

Before doing anything, we must decide what computational model we will be using for the analysis. The most common and useful are:

- [turing-machine](#turing-machine)
- [RAM model](#ram-model)

Also, our measures will often be asymptotic (input $n$ tends to infinity), so we must introduce some notation that will simplify writing messy limits all over: that is the role of [big O](#big-o) notation.

### Computation model

The fist thing to do is to decide on a computer model to work with.

#### Turing machine

Classical model.

#### RAM model

Random data access. Same computability class as Turing machine, but models currently existing memories better.

TODO vs Turing machine?

#### Input length vs value

Keep in mind that big O analysis uses a Turing machine, so what matters is the *length* of the input, *not* its value.

For example, deciding if a number $n$ is prime takes at most $\sqrt(n)$ steps (try dividing by each number smaller than $\sqrt(n)$), so one might think that deciding primeness is $Polynomial$.

However, $n$ is exponential on the number of digits of $n$! Adding a single digit 0 to the beginning of a number, multiplies it by 2 (in binary)!

Therefore, deciding primeness via trial division is not polynomial.

The practical importance of this depends on the nature of the input:

- if the input is man generated, such as a prime used for cryptography, it is easy to add lots zeros and ones to the beginning of a number so we have to consider the exponential aspect.

- if however $n$ is a number that comes out in some natural model in which $n$ itself cannot be too large because it cannot simply double too quickly (say, the number of people on the planet), then the exponential bound is not very meaningful.

#### Strongly NP

A problem is strongly NP if it is NP even if the input values are considered instead of the input lengths.

Therefore, the naive primeness test is not strongly NP complete, since if values were considered instead of input lengths, then it would be P.

Known strongly NP problems can be found here: <http://en.wikipedia.org/wiki/Category:Strongly_NP-complete_problems>

### Big O

Also known specially in physics as Landau notations.

Each is evaluated at the limit as x tends to some point, and this point is always taken by default to be infinity in complexity calculations.

- $f = O(g)$ iff exists $k$ in $R$ such that $f(x) <= k*g(x)$.

    This can be interpreted as $f$ is smaller than $g$

- $f = Omega(g)$ iff exists $k$ in $R$ such that $f(x) >= k*g(x)$.

    This can be interpreted as $f$ is larger than $g$

- $f = Theta(g)$ iff exists $k1$ and $k2$ in $R$ such that $k1*g(x) <= f(x) <= k2*g(x)$

    This can be interpreted as $f$ is the same as $g$.

### Recursive vs non recursive

For many algorithms, there are two methods to calculate the big O complexity: using a recursion relation or not.

It is often the case that using a recursion relation will be simpler, if not the only way, to compute the solution.

#### Recursive calculation

Comes down to a formula something like:

$$C(n) = C(n-1, n-2, ... 0)$$

where $C$ is the cost of time / memory for a given problem size.

This means that $C(n)$ is a function of the anterior values of $C$.

Special case of which comes up very often:

$$C(n) = a*C(n/b) + f(n)$$

Then in terms of $f$:

1. If $f(n) = O(n^{log(b, a - e)})$ for some constant $e > 0$, then $C(n) = Theta(n*log(b,a)$

2. If $f(n) = Theta(n^{log(b, a - e)})$, then $C(n) = Theta(n^{log_{b}(a)}*lg(n))$

3. If $f(n) = Omega(n^{log_{b}(a + e)})$ for some constant $e > 0$, and if af $(n/b) <= cf (n)$ for some $c < 1$, then $T(n) = Omega(f(n))$

### Analysis types

This section exemplifies the different types of analysis that can be done on al algorithm.

### Worst case

Most commonly used measure.

Takes the instance in which the algorithm runs the worst, and analyses it.

If this measure is good, then the algorithm is always good.

This does however leave out something: it is possible that worst cases are very rare considering all possible problems, and that the algorithm still performs well in practice. This is why two other types of analysis were created: [average](#average) and [amortized](#amortized) analysis.

### Best case

Like worst case, but for best case instead.

Not very often used.

### Average case

Like in worst case, we put a bound on the assymptotic average case.

Sources:

-   <https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/averagecase/pages/index.html>

    Good simple example.

### Amortized

Sources: [cormen] chapter "Amortized Analysis"

### Undecidability

<http://en.wikipedia.org/wiki/Undecidable_problem>

It can be proved that for certain problems, there is no Turing machine (and therefore any algorithm) that solves its instances.

Cool examples of such problems:

- halting problem. First discovered example. Proof of undecidability via cantors diagonal method.

There may however be Turing machines which solve specific families of instances, but there cannot be a finite number of such Turing machines that solve all problems, otherwise we could just run them all in parallel until one of them halts.

Those problems are called undecidable, and trying to solve them general is hopeless.
- P vs NP
- P vs NP

### P vs NP

The speed with which certain problems can be solved in terms of time and space
can be divided into two categories:

- polynomial
- non-polynomial: growth larger than any polynomial

The division is interesting because non-polyimial problems are *MUCH* harder to solve than polynomial ones.

Just consider the fact that on an exponential problem with $2^x$ complexit, increasing the problem size `x`
by one *doubles* the time it takes to solve the problem.

#### P

Problem can be solved by a Turing machine in polynomial time.

#### NP

Contains P

Problem solution can be verified, but not found, by a Turing machine in polynomial time.

For this reason, we want to believe that maybe they are easier to solve than other problems which we can't even check in polynomial time.

However, up to now, many NP problems can only be solved in exponential time, even if we can check them.

Example of NP problem: boolean satisfiability problem.

Non-example of NP problem: TSP. Even if we are given a solution, we cannot be sure that it is the optimum! This is often the case for optimization algorithms.

#### NP-complete

Contained, but not equal to NP.

It can be proven that all NP problems can be reduced to certain NP problems (NP-complete) in polynomial time.

Not all NP problems however are NP-complete.

#### Meaning of P vs NP

If a single NP-complete problem is proven to be in P, then all NP problems are also polynomial, and so P = NP.

This is what makes the P = NP question so interesting: if a single NP-complete problem is ever solved in P, every other NP problem can also be solved in P, and so P = NP

- if P = NP, every NP problem can be solved in polynomial time.

Since we have worked endless human hours searching for P algorithms to man NP-complete problems, it is widely believed that being NP-complete means that a problem cannot be solved in polynomial time.

- If P != NP, then we will be sure that all NP-complete really are hard, and that it is useless to search for P algorithms for them.

Important practical problems that are known to be NP-complete:

- knapsack problem (discrete linear programming)
- traveling salesman problem (discrete linear programming)

#### NP-hard

Problems such that there is an NP-complete problem that reduces to it in Polynomial time.

That means that if an NP-hard problem can be solved in polynomial time, then an NP-complete problem can also be solved in polynomial time, and `P = NP`.

All NP-complete problems are also NP-hard, but some NP-hard problems are not NP-complete.

Implications of P = NP to NP-hard problems:

- if P != NP, then all NP-hard problems cannot be solved in Polynomial time.

- if P == NP, then the NP-hard problems which are also NP-complete can be solved in polynomial time, but we know nothing about the NP-hard problems which are not NP-complete.

##### Decision vs optimization

It is very common to have optimization problems which are NP-hard, and for which the decision problem is NP-complete.

For example, in TSP, the decision problems are:

- is there a TSP path with cost at most 9?
- is there a TSP path with cost at most 10?
- ...

all of which are known to be NP-complete.

The optimization version of those problems is therefore immediately NP-hard, since if we knew that the optimum path has cost 5, we immediately know that there is at least one path with cost at most 9 or 10 (the path with cost 5), but no path with cost 4 (otherwise that would be the optimum).

## Divide and conquer

General algorithm design technique.

Applicable when the solution for size $n$ can be computed efficienty as the solution of smaller parts.

Example: merge sort.

## Dynamic programming

Sources: [skiena] chapter "Dynamic Programming"

General algorithm type.

Store solutions to subproblems that can be reused.

Can reduce time complexity dratically (from exponential to linear for example in the Fibonnacci sequence),
at the cost of potentially increasing memory complexity.

## Greedy algorithm

General type of algorithm that takes the local optimum first.

Disadvantage: may not converge to the optimal solutions when there are multiple local minima.

Advantages: very fast, and may give reasonable solutions in certain cases.

## Branch and bound

TODO
