# C++

The preferred source organization is:

- every `.cpp` file has a runnable main
- everything that is shared across multiple `.cpp` files gets implemented into an `.hpp`

Advantages:

- since each test has a main, we can test each algorithm independently from the others
- simpler to write the Makefile as there are no `.o` involved

Disadvantages:

- we cannot reuse already compiled `.hpp` parts
- we cannot reuse the main runners. The ideal reuse would be through a polymorphic interface. But then we'd lose the advantage of being able to compile and run each file independently.
