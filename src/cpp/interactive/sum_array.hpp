#ifndef SUM_ARRAY
#define SUM_ARRAY

static uintmax_t repeat = 0x1000;

void initInput(std::vector<uint64_t> &input) {
    /*
    16MiB. Way larger than CPU cache,
    but not so large that it takes a long time to allocate.
    */
    constexpr uint64_t size = 0x100000;
    input.resize(size);
    for (uint64_t i = 0; i < size; ++i)
        input[i] = i;
}

#endif
