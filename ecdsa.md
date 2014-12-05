# ECDSA

Elliptic Curve Digital Signature Algorithm.

## Requirements

Known public Key Cryptography in general will be helpful.

## Sources

-   <http://www.johannes-bauer.com/compsci/ecc/>

    Shows the computations step by step.

    Does not talk much about the deeper theory behind the curve.

## Vs RSA

Integer factorization was proposed in 1979, but many progresses were made.

ECC was proposed in 1985 but virtually no progress was made.

This is why new protocols that come out like bitcoin tend to use ECC.

TLS supports both RSA and ECC. As of 2014, RSA is much more popular because it came first.

## Asymmetry basis

Just like RSA, ECC is based on an operation which no one knows how to invert efficiently:
thus both are asymmetric cryptography.

In the case of RSA it is multiplication of primes.
For ECC it is elevating a finite group element to a power:
the inversion problem being called the
<http://en.wikipedia.org/wiki/Discrete_logarithm>

Shor's quantum algorithm would be able to break both efficiently.

## Signing

Like RSA, ECDSA can be used for both:

- encryption
- signature
