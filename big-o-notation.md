# Big O notation

The major concept to classify the complexity of algorithms.

Also known specially in physics as Landau notations.

Each is evaluated at the limit as x tends to some point, and this point is always taken by default to be infinity in complexity calculations.

-   $f = O(g)$ iff exists $k$ in $R$ such that $f(x) <= k*g(x)$.

    Intuitively, $f$ is *smaller* than $g$.

-   $f = Omega(g)$ iff exists $k$ in $R$ such that $f(x) >= k*g(x)$.

    Intuitively, $f$ is *larger* than $g$.

-   $f = Theta(g)$ iff exists $k1$ and $k2$ in $R$ such that $k1*g(x) <= f(x) <= k2*g(x)$

    Intuitively, $f$ is *equal* to $g$.
