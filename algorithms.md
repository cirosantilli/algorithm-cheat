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

Consists of proving that:

- correctness: the algorithm does that it advertises
- complexity: how fast and how much memory it takes to do it

## Correctness proofs

TODO

## Complexity proofs

The first thing to understand is how to model a computer: the most common way is to use a Turing Machine or one of its variants.

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

The calculation of the limit can be greatly simplified for recursive algorithms if you are able to solve the resulting **recurrence relation**.

One important idea is then to classify algorithm complexities into larger classes, e.g. P and NP. Those classifications are meaningful because exponential time algorithms will never be implementable in practice even for relatively small inputs. P vs NP is one of the many questions about the equality or not of such nested complexity classes.

### Worst case

Most commonly used measure.

Takes the instance in which the algorithm runs the worst, and analyses it.

If this measure is good, then the algorithm is always good.

This does however leave out something: it is possible that worst cases are very rare considering all possible problems, and that the algorithm still performs well in practice. This is why two other types of analysis were created: average and amortized analysis.

### Best case

Like worst case, but for best case instead.

Not very often used.

### Average case

Like in worst case, we put a bound on the asymptotic average case.

Sources:

-   <https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/averagecase/pages/index.html>

    Good simple example.

### Amortized

Sources: [cormen][] chapter "Amortized Analysis"

## Design patterns

High level design patters used when creating / classifying algorithms.

Those are not necessarily mathematically definable, and may represent only an intuitive perception of the problems. They are however very useful to help humans understand and create new algorithms.

Patterns not commented here:

- recursive algorithms

### Divide and conquer

General algorithm design technique.

Applicable when the solution for size $n$ can be computed efficiently as the solution of smaller parts.

Example: merge sort.

### Dynamic programming

Sources: [skiena][] chapter "Dynamic Programming"

General algorithm type.

Store solutions to subproblems that can be reused.

Can reduce time complexity drastically (from exponential to linear for example in the Fibonacci sequence),
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
- <http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/toc.htm>. Seems to be an HTML rip-off of Cormen's introduction to algorithms.

### Non-free sources

- [Skiena - Algorithm Design Manual 2ed][skiena]

- [Cormen - Introduction do Algorithms 2ed][cormen]

[cormen]: http://www.amazon.com/books/dp/0262033844
[skiena]: http://www.amazon.com/Algorithm-Design-Manual-Steven-Skiena/dp/1848000693
