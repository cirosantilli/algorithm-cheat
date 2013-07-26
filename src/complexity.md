This discusses algorithm complexity calculations.

The  fist thing to keep in mind is that all analysis are done on a Turing machine,
so you should learn how a turing machine works.

#turing machine

##input length vs value

Keep in mind that big O analysis uses a turing machine, so what matters is the *length*
of the input, *not* its value.

For example, deciding if a number $n$ is prime takes at most
$\sqrt(n)$ steps (try dividing by each number smaller than $\sqrt(n)$),
so one might think that deciding primeness is $Polynomial$.

However, $n$ is exponential on the number of digits of $n$! Adding a single digit 0
to the beginning of a number, multiplies it by 2 (in binary)!

Therefore, deciding primeness via trial division is not polynomial.

The practical importance of this depends on the nature of the input:

- if the input is man generated, such as a prime used for cryptography,
    it is easy to add lots zeroes and ones to the beginning of a number
    so we have to consider the exponential aspect.

- if however $n$ is a number that comes out in some natural model in which $n$ itself cannot
    be too large because it cannot simply double too quickly (say, the number of people on the planet),
    then the exponential bound is not very meaningful.

#big O

#worst case

##non-recursive calculation

##recursive calculation

#best case

#average case

#amortized
