# Quantum computing

## Sources

Non-free:

-   Chuang, Nilsen - 2010 - Quantum Computation and Quantum Information

    <http://www.johnboccio.com/research/quantum/notes/QC10th.pdf>

## General concepts

Quantum computation is at least as fast as classical computation,
and widely believed to be faster although that is unproven.

Quantum computing does not solve undecidable problems for classic computing:
it can only make some specific classes of problems solved faster.

The intuitive reason why quantum computers may be faster
is that they can carry out multiple operations at once,
since quantum systems like an electron calculate multiple trajectories at once probabilistically.

The problem is that observation of the output destroys part of the output information,
so clever techniques must be used to preserve some of the information
gained with that simultaneity.

Like classical computation, quantum computing can be split into two parts:

- modeling the computation from a high level point of view
- understanding how to implement the base computation steps physically

Quantum computers are at their infancy and their success is not certain,
but it is likely that the currently used model of quantum circuits will
model well any type of quantum computer likely to be built.

## Models

### Quantum circuit

<http://en.wikipedia.org/wiki/Quantum_circuit>

Most common model used.

<http://en.wikipedia.org/wiki/Quantum_gate>

Simulator: <http://www.davyw.com/quantum/>

All quantum gates are reversible: given the output you can know the input. TODO why?
As a consequence, the number of outputs is the same as the number of inputs.
This is not the case for many of the classical gates like AND.
There are however universal reversible classical gates.

Quantum gates are represented by unitary matrices.
A $k$ bit operation is represented by a $2^k x 2^k$ matrix.

Since quantum gates are always reversible,
any quantum circuit can be seen as a gate and represented by a matrix.

There exist universal quantum gates, e.g. the Deutsch gate.

### Quantum Turing Machine

<http://en.wikipedia.org/wiki/Quantum_Turing_machine>

Equivalent to the Quantum Circuit but less commonly used.

## Complexity classes

Two parameters have to be considered in terms of the input size:

- time to solve
- number of gates required, which may grow exponentially

### EQP

<http://en.wikipedia.org/wiki/EQP_%28complexity%29>

Exact Quantum Polynomial.

Quantum computer solves it polynomially with probability 1.

Quantum analog of P.

$P == EQP$ is open.

### BQP

Bounded Quantum Polynomial.

Quantum version of BPP.

We know:

-   $BQP \subset PSPACE$. Equality open but believed false.

    Disproving it should be hard as it would imply $P \subset PSPACE$ which is widely studied.

-   $NP \subset BQP$ is open but believed to be false.

-   $P == BQP$ is open but believed to be false because of known quantum algorithms without known P.

### Vs probabilistic TM

Quantum machines are probabilistic.

There is a relation between BPP and QTM. TODO

## Quantum algorithms

### Shor's algorithm

<http://en.wikipedia.org/wiki/Shor%27s_algorithm>

Integer factorization in $log(N)^3$, but exponentially many gates.

Great improvement over the best classic factorization algorithm known:
<http://en.wikipedia.org/wiki/General_number_field_sieve>
which is sub exponential.

Generates huge interest since could break RSA,
and many quantum computer prototypes have showcased it.

### Grover's algorithm

<http://en.wikipedia.org/wiki/Grover%27s_algorithm>

Search in unsorted array with $O(N^{1/2})$.

Proven to be the optimal quantum algorithm for this problem, while the optimal classic algorithm is $O(N)$

Probabilistic.

This quantum algorithm only produces a polynomial improvement ($N^{1.2}$) over the optimal classical algorithm,
but there are others which may produce exponential improvements.

Not too important in practice since search on a sorted set is $log(N)$.
