#!/usr/bin/env python

import sys

def newton(f, fp, x0, eps):
    x = x0
    niter = 0
    xs = []
    while f(x) > eps:
        x = x - f(x)/fp(x)
        niter += 1
        xs.append(x)
    return x, niter, xs

if len(sys.argv) > 1:
    eps = float(sys.argv[1])
else:
    eps = 1E-6
print newton(lambda x: x*x, lambda x: 2.0*x, 5.0, eps)
print newton(lambda x: (x - 5) ** 3, lambda x: 3 * (x - 5) ** 2, 9.0, eps)
