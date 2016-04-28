#ifndef CPU_BOUND
#define CPU_BOUND

constexpr static uint64_t nIters = 0x10000000;

/* Any funky operation that the compiler is unlikely to optimize away. */
static void cpu_bound(uint64_t *io, uint64_t iterations) {
    uint64_t out = *io;
    for (uint64_t i = 0; i < iterations; ++i)
        out += out*out + 2*out + 1;
    *io = out;
}

#endif
