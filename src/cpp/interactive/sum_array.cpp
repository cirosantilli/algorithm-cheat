#include "common.hpp"
#include "sum_array.hpp"

/*
The goal of this function is to compare speed with a multi-threaded program.
*/
template<typename T = uint64_t>
T sum_array(std::vector<T>& input, uintmax_t repeat) {
    T sum = 0;
    for (uintmax_t i = 0; i < repeat; ++i)
        for (auto& n : input)
            sum += n;
    return sum;
}

int main() {
    std::vector<uint64_t> input;
    initInput(input);
    std::cout << sum_array(input, repeat) << '\n';
}
