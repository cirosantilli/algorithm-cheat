# Turing machine

# Computation model

Review of Turing machines and it's variants.

The Turing machine and variants is the most popular model to model computations, so understanding it is fundamental before you do anything else.

Different models exist to represent different capabilities of real, or imaginary, hardware.

## Variants

### Classical model

Classical model.

### Non-deterministic Turing Machine

### NTM

Turing machine that has multiple possible transitions per input and state.

It decides between those transitions either:

- optimally through a magic oracle.
- by following all paths at once. TODO: what is the correct output if multiple paths halt?

### RAM

Random data access. Same computability class as Turing machine, but models currently existing memories better.

TODO vs Turing machine?

### PRAM

### Parallel random-access machine

<http://en.wikipedia.org/wiki/Parallel_random-access_machine>

## Input length vs value

Keep in mind that big O analysis uses a Turing machine, so what matters is the *length* of the input, *not* its value.

For example, deciding if a number $n$ is prime takes at most $\sqrt(n)$ steps (try dividing by each number smaller than $\sqrt(n)$), so one might think that deciding primeness is $Polynomial$.

However, $n$ is exponential on the number of digits of $n$! Adding a single digit 0 to the beginning of a number, multiplies it by 2 (in binary)!

Therefore, deciding primeness via trial division is not polynomial.

The practical importance of this depends on the nature of the input:

- if the input is man generated, such as a prime used for cryptography, it is easy to add lots zeros and ones to the beginning of a number so we have to consider the exponential aspect.

- if however $n$ is a number that comes out in some natural model in which $n$ itself cannot be too large because it cannot simply double too quickly (say, the number of people on the planet), then the exponential bound is not very meaningful.

### Strongly NP

A problem is *strongly NP* if it is NP even if the input values are considered instead of the input lengths.

Therefore, the naive primeness test is not strongly NP complete, since if values were considered instead of input lengths, then it would be P.

Known strongly NP problems can be found here: <http://en.wikipedia.org/wiki/Category:Strongly_NP-complete_problems>
