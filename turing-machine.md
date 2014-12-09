# Turing machine

Also mentions other computation models and how they compare to Turing machines.

## Computation model

The fist thing to do is to decide on a computer model to work with.

### Turing machine

Classical model.

#### Variants

Variants mentioned in other sections include:

- Probabilistic Turing Machine
- Quantum Turing Machine

##### Non-deterministic Turing Machine

##### NTM

Turing machine that has multiple possible transitions per input and state.

It decides between those transitions either:

- optimally through a magic oracle.
- by following all paths at once. TODO: what is the correct output if multiple paths halt?

#### Limitations of Turing machines

While Turing machines accurately describe decidability of existing systems, it does not model performance so well for the following reasons:

- modern computers have random access memory. Fortunately it is simple to model performance by using the so called RAM computation model.

- out-of-core operations: for very large inputs, it is necessary to store data in lower speed access media like hard disks. It then becomes necessary to model how much slower those accesses are.

### RAM model

Random data access. Same computability class as Turing machine, but models currently existing memories better.

TODO vs Turing machine?

### Out of core

### External memory

Sometimes algorithms must operate on data that is too large to fit in RAM, e.g. hard disks. In those cases, it may be necessary to take that into consideration, since disk IO is 1000 slower than RAM access.

Certain algorithms are developed with that restriction in mind, e.g., the B-tree, which is less efficient than other binary search trees for in RAM computing, but much more efficient of out-of-core problems.

There is no simple way of modeling the performance of out-of-core algorithms: we just have to give different weights to certain operations, and then solve complex numerical optimization decisions.

### Input length vs value

Keep in mind that big O analysis uses a Turing machine, so what matters is the *length* of the input, *not* its value.

For example, deciding if a number $n$ is prime takes at most $\sqrt(n)$ steps (try dividing by each number smaller than $\sqrt(n)$), so one might think that deciding primeness is $Polynomial$.

However, $n$ is exponential on the number of digits of $n$! Adding a single digit 0 to the beginning of a number, multiplies it by 2 (in binary)!

Therefore, deciding primeness via trial division is not polynomial.

The practical importance of this depends on the nature of the input:

- if the input is man generated, such as a prime used for cryptography, it is easy to add lots zeros and ones to the beginning of a number so we have to consider the exponential aspect.

- if however $n$ is a number that comes out in some natural model in which $n$ itself cannot be too large because it cannot simply double too quickly (say, the number of people on the planet), then the exponential bound is not very meaningful.

#### Strongly NP

A problem is *strongly NP* if it is NP even if the input values are considered instead of the input lengths.

Therefore, the naive primeness test is not strongly NP complete, since if values were considered instead of input lengths, then it would be P.

Known strongly NP problems can be found here: <http://en.wikipedia.org/wiki/Category:Strongly_NP-complete_problems>
