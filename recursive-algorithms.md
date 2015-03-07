# Recursive algorithms

One common algorithm design pattern is to use recursion, i.e., a function that calls itself, but each time with an input that is closer to the solution.

Recursive implementations must have *base case* after which recursion is not called anymore. Each call must put the inputs closer to the base case.

Many recursive algorithms can be transformed into a non-recursive version with call elimination, i.e. replacing recursive calls with with a loop. The trade-offs are:

- the recursive version is simpler to write
- the non-recursive version is more memory and time efficient because it does not generate a stack trace

More precisely, it is exactly tail recursive algorithms that can go through call elimination.

In functional programming languages, call elimination is not possible explicitly. However, many of those languages specify in their standard that call elimination is guaranteed to be done by the compiler. GCC is capable of doing TRO with the `-O2` flag.

## Tail call

## Tail recursive optimization

## TRO

A tail call is a function call that happens just before a function returns.

It does not need to be a call to the current function. But if it is, it is called a *recursive tail call*, and may be simpler to optimize.

Non-example of tail call:

    int factorial(int n)
        if n == 1
            return 1
        return factorial(n - 1) * n

Not a tail call because the processor must return to the return statement to do `factorial(n - 1) * n` before returning it.

If we were worried about performance, we should try to convert it into a tail call version, which will make it easier for the compiler to optimize:

    int factorial(int n)
        return factorial-accum(n, 1)

    int factorial-accum(int n, int accum)
        if n == 1
            return accum
        else
            return factorial-accum(n - 1, n * accum)

It is then trivial for a compiler to automatically convert it to:

    int factorial-accum(n, accum)
        TOP
        if n == 1
            return accum
        n = n - 1
        accum *= n
        goto TOP

and the recursion is now gone!
