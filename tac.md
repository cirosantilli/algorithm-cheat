# Tac

<https://www.gnu.org/software/coreutils/manual/html_node/tac-invocation.html>

## Discussion

<http://www.gnu.org/software/coreutils/manual/html_node/tac-invocation.html>

`cat` reversed line-wise.

The hard part is implementing this with out-of-core considerations:

- RAM is finite, otherwise we could just read everything at once and it would be simple
- disk access is extremely slow, otherwise we could just read one character at a time and put it into the buffer

The first naive idea that comes to mind is:

- read a chunk
- go backwards until the last line
- read a smaller chunk
- the first time we print, print what was left from the previous
- repeat

But this simple strategy would not work because using the notation:

- `n`: newline
- `.`: any character
- digit: first character of the nth line to be printed
- `' '` (space): the character has already been printed

the buffer would evolve as follows:

    Read 1

    | 3 . . . . n 2 . . n 1 n |

    | 3 . . . . n 2 . . n     |

    | 3 . . . . n             |

    Read 2

    | 3 . . . . n 4 n 3 . . . |

    |             4 n         |

    Read 3

    |             4 n 5 . n 4 |

    |                 5 . n   |

    Read 4

    |                 5 . n 5 |

Note how at each step the read is reduced, and at the front there is a lot of wasted memory.

The solution is to use a circular buffer: <https://en.wikipedia.org/wiki/Circular_buffer>.

There are two possible implementations:

Double buffer implementation:

- use two buffers of equal size
- read into one of the two cyclically

Circular buffer implementation:

- read two chunks from disk every time

Advantage of circular: uses half the RAM.

Disadvantage: twice as many disk reads, which are *very* expensive.

So in general the double buffer is better.

With the double buffer technique, it would work as follows:

    Read 1

    | 3 . . . . n 2 . . n 1 n |
    |                         |

    | 3 . . . . n 2 . . n     |
    |                         |

    | 3 . . . . n             |
    |                         |

    Read 2

    | 3 . . . . n             |
    | n 5 . n 4 . . n 3 . . . |

    |                         |
    | n 5 . n 4 . . n         |

    |                         |
    | n 5 .n                  |

    |                         |
    | n                       |

    Read 3

    | 8 . . . . n 7 . . n 6 n |
    | n                       |

    | 8 . . . . n 7 . . n 6 n |
    |                         |

    | 8 . . . . n 7 . . n     |
    |                         |

    | 8 . . . . n             |
    |                         |

And so on.
