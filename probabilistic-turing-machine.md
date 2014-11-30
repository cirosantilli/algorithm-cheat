# Probabilistic Turing Machine

Each transition happens with a given probability.

PTMs are a generalization of the deterministic machine, since you can get a deterministic machine by setting all probabilities to either 0 or 1.

## Applications

-   Quantum Turing Machines are probabilistic and physically realisable.

-   Cryptography uses Probabilistic Turing Machines in their proofs,
    since key concepts like SHA inversion are only meaningful statistically.

## BPP

<http://en.wikipedia.org/wiki/BPP_%28complexity%29>

Bounded Probabilistic Polynomial.

-   runs polynomially for every input. In particular, this implies that it always halts on a correct or incorrect answer.

-   gives the correct answer with probability greater than a fixed number larger than 0.5.

    Note that this is equivalent to saying it gives the right result at least $2/3$ of the time:
    you just have to create a new PTM that runs $n$ times and chooses the most common output.

    This implies that if you run it enough times, it tends with probability 1 to the right answer.

P == BPP is open.
PRIMES was a famous problem known for a long time to be in BPP but a P was found in 2002.
A famous problem in BPP but unknown P is polynomial identity testing:
test if two polynomials are equal.
The naive method of expanding the polynomial is not P because, e.g.:

$$(x_0 + x_1)(x_1 + x_2) ... (x_{n-1} x_n)$$

expands to $2^n$ terms, even though it is only $O(n)$ in initial size.

### Las Vegas algorithm

<http://en.wikipedia.org/wiki/Las_Vegas_algorithm>

Algorithms like BPP but without the polynomial constraint.

Contrast with Monte Carlo algorithms.

## ZPP

- It always runs in polynomial time.
- It returns an answer YES, NO or DO NOT KNOW.
- The answer is always either DO NOT KNOW or the correct answer.
- It returns DO NOT KNOW with probability at most 1/2 (and the correct answer otherwise).

I guess a common design pattern for this is to take a regular algorithm
and decide when to cut off execution intelligently giving the DO NOT KNOW.

### Monte Carlo algorithms

<http://en.wikipedia.org/wiki/Monte_Carlo_algorithm>

Algorithms like ZPP but without the polynomial constraint.

Contrast with Las Vegas algorithms.
