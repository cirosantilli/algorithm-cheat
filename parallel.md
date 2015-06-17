# Parallel

## Primitives

<http://stackoverflow.com/questions/2368164/how-is-thread-synchronization-implemented-at-the-assembly-language-level>

- language agnostic: spinlock
- x86: `lock`, `xadd`, `cmpxchg` (CAS)
- Linux system calls: `futex`, `semctl`
