# Out of core algorithms

# IO algorithms

# External memory

<http://en.wikipedia.org/wiki/Out-of-core_algorithm>

Sometimes algorithms must operate on data that is too large to fit in RAM, e.g. hard disks. In those cases, it may be necessary to take that into consideration, since disk IO is 1000 slower than RAM access.

Certain algorithms are developed with that restriction in mind, e.g., the B-tree, which is less efficient than other binary search trees for in RAM computing, but much more efficient of out-of-core problems.

There is no simple way of modeling the performance of out of core algorithms: we just have to give different weights to certain operations, and then solve complex numerical optimization decisions.

Sample problems:

-   read several different sized inputs from a file, e.g. one per line, in a way that each line must be completely loaded and processed at a time.

    This could happen if you have for example a file with many inputs to be sorted like:

        3 1 2
        3
        14 3 2 1 2

    The `tac` command line utility (`cat` reversed line-wise, in GNU Coreutils) is another example. While `cat` can be implemented trivially (you don't need to have the entire line to print it to stdout), `tac` must first read entire lines backwards before putting them on stdout.

## Sources

- <http://users-cs.au.dk/large/ioS12/>
- <http://www.win.tue.nl/~hermanh/teaching/2IL35/>
