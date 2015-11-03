/*
Parallelization here is useless because this is memory bound:
http://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean
*/


#include "common.hpp"
#include "sum_array.hpp"

#define size_type_t typename std::vector<T>::size_type

/*
TODO pass by reference insted of pointer. This creates a problem:
http://stackoverflow.com/questions/28950835/c-error-no-type-named-type-in-class-stdresult-ofvoid-stdunordered
*/
template<typename T = uint64_t>
static void sum(
        const std::vector<T> *input,
        const size_type_t start,
        const size_type_t end,
        uintmax_t repeat,
        T *output) {
    for (uintmax_t i = 0; i < repeat; ++i)
        for (size_type_t j = start; j < end; ++j) {
            *output += (*input)[j];
            //*output += 1;
            //*output += *output**output + 2**output + 1;
        }
}

template<typename T = uint64_t>
T sum_array(const std::vector<T>& input, uintmax_t repeat) {
    uint64_t i, nThreads;
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
        threads[i] = std::thread(sum<T>, &input, start, end, repeat, &outputs[i]);
        start += width;
        end += width;
    }
    threads[nThreads - 1] = std::thread(sum<T>, &input, start, inputSize, repeat, &outputs[nThreads - 1]);
    for (i = 0; i < nThreads; ++i) {
        threads[i].join();
    }

    delete[] threads;
    output = 0;
    sum(&outputs, 0, nThreads, 1, &output);
    return output;
}

int main() {
    std::vector<uint64_t> input;
    initInput(input);
    std::cout << sum_array(input, repeat) << '\n';
}
