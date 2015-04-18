# Getting started

## Dependencies

- `make` (POSIX)
- Python 2 for the `test` script
- `gcc` >= 4.8
- `g++` >= 4.8
- Java >= 1.7

## Usage

Run a single test:

    ./test QuickSort.java

or equivalently:

    ./test src/java/QuickSort.java

This will build the program, choose and feed input data to it, and check if the output is as expected.

Run all tests of for a given language:

    ./test java

or equivalently:

    ./test src/java

Run all tests for all languages:

    ./test

More info at (TODO implement help command):

    ./test --help
