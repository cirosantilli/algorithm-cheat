# Cryptography

## Public key cryptography

Public key cryptography is a way to do cryptography so that it is not necessary
to exchange secret data before the actual data is transferred:
an transactions are public.

Main functions provided are:

- secrecy: send a message so that no one can read it except the recipient.
- signature: make sure that a message comes from who it claims to come.

Some algorithms may only provide some of those functions.

Algorithms are based on mathematical operations which are fast to calculate,
but too slow to inverse.

Main algorithms are:

-   RSA

    Multiplication / Factorization problem.

    Both secrecy and signature.

-   Diffie-Hellman

    Discrete Exponent mod n / Discrete logarithm mod n problem.

    Only provides secrecy.

## Cryptographic hash function

<http://en.wikipedia.org/wiki/checksum_algorithm>

Used in cryptography as well as other applications,
e.g. Git SHA to identify objects uniquely.

Desired properties:

-   it is easy to compute the hash value for any given message

-   it is infeasible to generate a message that has a given hash

-   it is infeasible to modify a message without changing the hash

-   it is infeasible to find two different messages with the same hash.

    This is in general much easier than finding an input with a given hash because of
    the birthday problem: <http://en.wikipedia.org/wiki/Birthday_problem>

### Implementations

#### SHA-1

160 bits.

SHA-1 is the most popular in 2014. Used in Git.

Attacks were found in 2005, but they are were too expensive.

Some parts of the US government moved to SHA-2 in 2010 because of the weaknesses.

SHA-1 will be practical in 2018 for organized crime:
<https://www.schneier.com/blog/archives/2012/10/when_will_we_se.html>

Google, Microsoft and Mozilla will remove SHA-1
for security in 2017 and use SHA-2 instead.

SHA-1 prefix fixing already practical in 2014 on personal computers:
<https://github.com/bradfitz/gitbrute>

#### SHA-2

Family of 6 functions and output lengths.
