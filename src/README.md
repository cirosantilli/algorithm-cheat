# src

Educational implementations of algorithms.

For serious applications use real libraries like Boost.

Multiple significantly different implementations are accepted, including in different languages and using different libraries.

Add the `.off` extension to WIP files to prevent their compilation.

## Program interfaces

### Data on separate file

The preferred program interface:

- takes input from a data file give as a command line argument, e.g. `./program /path/to/data/0.in`
- outputs the output to stdout
- outputs diagnostic messages to stderr
- the exit status must be 0 on success

The advantages of this method are that:

- it is language agnostic
- it factors out the error checking across all algorithms

Although stdin input is more elegant as it does not require file IO, file input is more general as it allow for out-of-core considerations.

File output may also be supported some day if we find cool optimizations that need it.

### Data with the algorithm or with the language

If you have just created a program, it may be faster to put the data and assertions into:

- the algorithm file directly
- a shared file for the language

and only return its output via the exit status, with `0` for success and non-zero for failure.

But it has the following downsides:

- cannot share the data across languages
- you must recompile on data changes

So only use this if you are lazy and have only a single program that takes a given type of input.
