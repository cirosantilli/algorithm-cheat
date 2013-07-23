This discusses complexity classes such as P and NP

#intro

The speed with which certain problems can be solved in terms of time and space
can be divided into two categories:

- polynomial
- non-polynomial: growth larger than any polynomial

The division is interesting because non-polyimial problems are *MUCH* harder to solve than polynomial ones.

Just consider the fact that on an exponential problem with $2^x$ complexit, increasing the problem size `x`
by one *doubles* the time it takes to solve the problem.

#cool

- [P vs NP](p-vs-np)

#P

Problem can be solved by a turing machine in polynomial time.

#NP

Contains P

Problem solution can be verified, but not found, by a turing machine in polynomial time.

For this reason, we want to believe that maybe they are easier to solve than other problems
which we can't even checkec in polynomial time.

However, up to now, many NP problems can only be solved in exponential time, even if we can check them.

#NP-complete

Contained, but not equal to NP.

It can be proven that all NP problems can be reduced to certain NP problems (NP-complete) in polynomial time.

Not all NP problems however are NP-complete.

#P vs NP

If a single NP-complete problem is proven to be in P,
then all NP problems are also polynomial, and so P = NP.

This is what makes the P = NP question so interesting:
if a single NP-complete problem is ever solved in P, every other NP problem can also be solved in P,
and so P = NP

- if P = NP, every NP problem can be solved in polynomial time.

Since we have worked endeless human hours searching for P algorithms to manh NP-complete problems,
it is widely believed that being NP-complete means that a problem cannot be solved in polynomial time.

- If P != NP, then we will be sure that all NP-complete really are hard,
    and that it is useless to search for P algorithms for them.

Important practical problems that are known to be NP-complete:

- knapsack problem (discrete linear programming)
- travelling salesman problem (discrete linear programming)

#NP-hard

Contained but not equal to NP.

Problems that reduce to NP-complete problems in polynomial time.

If P != NP, then those problems also cannot be solved in Polynomial time.
If P == NP, then those problems can be solved in Polynomial time.
