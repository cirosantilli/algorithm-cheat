# Recurrence relations

When the running time of an algorithm can be expressed in term of the running time of the algorithm itself, but with a smaller input, we have a recurrence relation.

It is often the case that recurrence relations are the easiest way to carry ou

Mathematically, this means that the complexity can be expressed as:

$$complexity(n) = complexity(n-1, n-2, ... 0)$$

This means that $C(n)$ is a function of the anterior values of $C$.

Recurrence relations are analogous to a discrete differential equations. Solutions are known to most of the interesting cases you are likely to find, so if you manage to reduce your analysis to one, you are usually done. Because of this, finding a recurrence relation is often the easiest way of solving a problem.

Recurrence relations come up often in algorithm analysis because the analysis of recursive algorithms naturally falls back to them.

## Master theorem

Set of formulas popularized by Cormen's Introduction to algorithms textbook.

Those formulas are not super fundamental in a mathematical sense, but they are very useful in practical analysis.

$$C(n) = a*C(n/b) + f(n)$$

Then in terms of $f$:

1. If $f(n) = O(n^{log(b, a - e)})$ for some constant $e > 0$, then $C(n) = Theta(n*log(b,a)$

2. If $f(n) = Theta(n^{log(b, a - e)})$, then $C(n) = Theta(n^{log_{b}(a)}*lg(n))$

3. If $f(n) = Omega(n^{log_{b}(a + e)})$ for some constant $e > 0$, and if $(n/b) <= cf (n)$ for some $c < 1$, then $T(n) = Omega(f(n))$

There are however many cases which don't fall into the master theorem.

## Akra–Bazzi method

<http://en.wikipedia.org/wiki/Akra%E2%80%93Bazzi_method>

Solution method to a large set of recurrence relations of the form shown on the wiki article.

## Solving recurrence relations

In the rare case that you fall on a recurrence relation to which you don't have a solution, you'll need to do some extra work.
