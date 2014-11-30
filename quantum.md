# Quantum

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

### EQP

<http://en.wikipedia.org/wiki/EQP_%28complexity%29>

Exact Quantum Polynomial.

Quantum computer solves it polynomially with probability 1.

Quantum analog of P.

### Vs probabilistic TM

Quantum machines are probabilistic.

There is a relation between BPP and QTM. TODO

## Quantum algorithms

### Grover's algorithm

<http://en.wikipedia.org/wiki/Grover%27s_algorithm>

Search in unsorted array with $O(N^{1/2})$.

Proven to be the optimal quantum algorithm for this problem, while the optimal classic algorithm is $O(N)$

Probabilistic.
