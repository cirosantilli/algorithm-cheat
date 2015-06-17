/**
I have profiled this compared to the non-parallel version
in inputs of 10M integers and it only gave a 50% performance improvement
(gprof of sum_array, file IO not included).
*/

#include <cmath>
#include <thread>
#include <vector>

#include "common.hpp"

#define size_type_t typename std::vector<T>::size_type

/*
TODO pass by reference insted of pointer. This creates a problem:
http://stackoverflow.com/questions/28950835/c-error-no-type-named-type-in-class-stdresult-ofvoid-stdunordered
*/
template<typename T = int>
static void sum(
        const std::vector<T> *input,
        size_type_t start,
        const size_type_t end,
        T *output) {
    while (start < end) {
        *output += (*input)[start];
        start++;
    }
}

template<typename T = int>
T sum_array(const std::vector<T>& input) {
    unsigned int i, nThreads;
    size_type_t inputSize, start, width, end;
    T output;
    std::vector<T> outputs;

    inputSize = input.size();
    nThreads = std::min(
            (unsigned int)inputSize,
            std::thread::hardware_concurrency());
    std::thread *threads = new std::thread[nThreads];
    outputs = std::vector<T>(nThreads);
    width = inputSize / nThreads;

    start = 0;
    end = width;
    for (i = 0; i < nThreads - 1; ++i) {
        threads[i] = std::thread(sum<T>, &input, start, end, &outputs[i]);
        start += width;
        end += width;
    }
    threads[nThreads - 1] = std::thread(sum<T>, &input, start, inputSize, &outputs[nThreads - 1]);
    for (i = 0; i < nThreads; ++i) {
        threads[i].join();
    }

    delete[] threads;
    output = 0;
    sum(&outputs, 0, nThreads, &output);
    return output;
}

int main(int argc, char **argv) {
    std::vector<int> input = parse_array(argv[1]);
    std::cout << sum_array(input) << '\n';
}
