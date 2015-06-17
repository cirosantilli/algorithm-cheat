#include <vector>

#include "common.hpp"

/*
The goal of this function is to compare speed with a multi-threaded program.
*/
template<typename T = int>
T sum_array(std::vector<T>& input) {
    int sum = 0;
    for (auto& n : input)
        sum += n;
    return sum;
}

int main(int argc, char **argv) {
    std::vector<int> input = parse_array(argv[1]);
    std::cout << sum_array(input) << '\n';
}
