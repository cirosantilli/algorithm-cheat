# Algorithms

General algorithm concepts.

Specific algorithms will not be discussed here.

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

Before doing anything, we must decide what computational model we will be using for the analysis. The most common and useful are:

- Turing machine
- RAM model

First, one must decide if algorithms exist or not. There are problems for which there is no Turing machine that solves it, so their solution is hopeless: these are the undecidable problems.

The following types of analysis give useful measures on how efficient an algorithm is in each of the resources:

- worst case
- best case
- average case
- amortized

Also, our measures will often be asymptotic (input $n$ tends to infinity), so we must introduce some notation that will simplify writing messy limits all over: that is the role of big O notation.

One important idea is then to classify algorithm complexities into larger classes, e.g. P and NP. Those classifications are meaningful because exponential time algorithms will never be implementable in practice even for relatively small inputs. P vs NP is one of the many questions about the equality or not of such nested complexity classes.

### Computation model

The fist thing to do is to decide on a computer model to work with.

#### Turing machine

Classical model.

##### Variants

###### Non-deterministic Turing Machine

###### NTM

Turing machine that has multiple possible transitions per input and state.

It decides between those transitions either:

- optimally through a magic oracle.
- by following all paths at once. TODO: what is the correct output if multiple paths halt?

##### Limitations of Turing machines

While Turing machines accurately describe decidability of existing systems, it does not model performance so well for the following reasons:

- modern computers have random access memory. Fortunately it is simple to model performance by using the so called RAM computation model.

- out-of-core operations: for very large inputs, it is necessary to store data in lower speed access media like hard disks. It then becomes necessary to model how much slower those accesses are.

#### RAM model

Random data access. Same computability class as Turing machine, but models currently existing memories better.

TODO vs Turing machine?

#### Out of core

#### External memory

Sometimes algorithms must operate on data that is too large to fit in RAM, e.g. hard disks. In those cases, it may be necessary to take that into consideration, since disk IO is 1000 slower than RAM access.

Certain algorithms are developed with that restriction in mind, e.g., the B-tree, which is less efficient than other binary search trees for in RAM computing, but much more efficient of out-of-core problems.

There is no simple way of modeling the performance of out-of-core algorithms: we just have to give different weights to certain operations, and then solve complex numerical optimization decisions.

#### Input length vs value

Keep in mind that big O analysis uses a Turing machine, so what matters is the *length* of the input, *not* its value.

For example, deciding if a number $n$ is prime takes at most $\sqrt(n)$ steps (try dividing by each number smaller than $\sqrt(n)$), so one might think that deciding primeness is $Polynomial$.

However, $n$ is exponential on the number of digits of $n$! Adding a single digit 0 to the beginning of a number, multiplies it by 2 (in binary)!

Therefore, deciding primeness via trial division is not polynomial.

The practical importance of this depends on the nature of the input:

- if the input is man generated, such as a prime used for cryptography, it is easy to add lots zeros and ones to the beginning of a number so we have to consider the exponential aspect.

- if however $n$ is a number that comes out in some natural model in which $n$ itself cannot be too large because it cannot simply double too quickly (say, the number of people on the planet), then the exponential bound is not very meaningful.

##### Strongly NP

A problem is *strongly NP* if it is NP even if the input values are considered instead of the input lengths.

Therefore, the naive primeness test is not strongly NP complete, since if values were considered instead of input lengths, then it would be P.

Known strongly NP problems can be found here: <http://en.wikipedia.org/wiki/Category:Strongly_NP-complete_problems>

### Big O

*The* major concept to classify algorithms.

Also known specially in physics as Landau notations.

Each is evaluated at the limit as x tends to some point, and this point is always taken by default to be infinity in complexity calculations.

-   $f = O(g)$ iff exists $k$ in $R$ such that $f(x) <= k*g(x)$.

    This can be interpreted as $f$ is smaller than $g$

-   $f = Omega(g)$ iff exists $k$ in $R$ such that $f(x) >= k*g(x)$.

    This can be interpreted as $f$ is larger than $g$

-   $f = Theta(g)$ iff exists $k1$ and $k2$ in $R$ such that $k1*g(x) <= f(x) <= k2*g(x)$

    This can be interpreted as $f$ is the same as $g$.

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

### Recursive vs non recursive proofs

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

## Design patterns

This section describes high level design patters used when creating algorithms.

Those are not necessarily mathematically definable, and may represent only an intuitive perception of the problems.

### Divide and conquer

General algorithm design technique.

Applicable when the solution for size $n$ can be computed efficiently as the solution of smaller parts.

Example: merge sort.

### Dynamic programming

Sources: [skiena] chapter "Dynamic Programming"

General algorithm type.

Store solutions to subproblems that can be reused.

Can reduce time complexity dratically (from exponential to linear for example in the Fibonnacci sequence),
at the cost of potentially increasing memory complexity.

### Greedy algorithm

General type of algorithm that takes the local optimum first.

Disadvantage: may not converge to the optimal solutions when there are multiple local minima.

Advantages: very fast, and may give reasonable solutions in certain cases.

### Branch and bound

TODO

### Online algorithm

<http://en.wikipedia.org/wiki/Online_algorithm>

An algorithm that can take it's input little by little: it does not need the entire input all at once to process it.

If such algorithm is possible, the advantage is obvious: it uses less memory for large inputs.

## Sources

### Free sources

Lecture notes:

- <http://webdocs.cs.ualberta.ca/~holte/t26/top.realtop.html>
- <https://secweb.cs.odu.edu/~zeil/cs361/web/website/directory/page/topics.html>

### Non-free sources

- [Skiena - Algorithm Design Manual 2ed][skiena]

- [Cormen - Introduction do Algorithms 2ed][cormen]

[cormen]: http://www.amazon.com/books/dp/0262033844
[skiena]: http://www.amazon.com/Algorithm-Design-Manual-Steven-Skiena/dp/1848000693
