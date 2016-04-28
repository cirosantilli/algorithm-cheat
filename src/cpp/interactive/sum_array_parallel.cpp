/*
Test parallel array sum vs sequential.
Run multiple number of threads to see how it scales.
Parallelization is only of limited use because we quickly become IO-bound:
http://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean
*/

#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

// Size of vectors to be added.
constexpr size_t SIZE = 0x100000u;
// How many vector additions will be done,
// to get better averages for parallel processing.
constexpr uintmax_t REPEAT = 0x10u;
typedef uint64_t dataType;

// TODO no stdlib for this?
class Callable {
    public:
        virtual void operator()() const = 0;
};

template<typename T = int>
class SumArray : public Callable {
    public:
        SumArray() {}
        SumArray(const T *input, size_t size, T *output, size_t step = 1) :
            input(input), size(size), output(output) {}
        virtual void operator()() const {
            size_t i;
            T sum = 0;
            for (i = 0; i < this->size; ++i)
                sum += this->input[i];
            *(this->output) = sum;
        }
    protected:
        const T *input;
        T *output;
        size_t size;
};

template<typename T = int>
class SumArrayParallel : public SumArray<T> {
    public:
        SumArrayParallel() {}
        SumArrayParallel(const T *input, size_t size, T *output, unsigned int nThreads) :
            SumArray<T>(input, size, output), nThreads(nThreads) {}
        virtual void operator()() const {
            size_t start, width, end;
            std::vector<T> outputs;
            uint64_t i, nThreads;
            unsigned int actualNThreads;

            actualNThreads = std::min(
                    (unsigned int)this->size,
                    this->nThreads);
            std::vector<std::thread> threads(actualNThreads);
            outputs = std::vector<T>(actualNThreads);
            width = this->size / actualNThreads;

            start = 0;
            for (i = 0; i < actualNThreads - 1; ++i) {
                threads[i] = std::thread(&SumArray<T>::operator(),
                        SumArray<T>(&this->input[start], width, &outputs[i]));
                start += width;
            }
            threads[actualNThreads - 1] = std::thread(&SumArray<T>::operator(),
                    SumArray<T>(&this->input[start], this->size - start, &outputs[actualNThreads - 1]));
            for (i = 0; i < actualNThreads; ++i) {
                threads[i].join();
            }

            SumArray<T>(outputs.data(), actualNThreads, this->output)();
        }
    private:
        unsigned int nThreads;
};

int main() {
    std::size_t i;
    std::vector<std::chrono::duration<double>> dts;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::vector<dataType> input(SIZE);
    std::vector<Callable*> callables;
    dataType output;
    std::vector<dataType> repeatOutputs;
    std::uintmax_t r;
    unsigned int nCores, totalTests;

    nCores = std::thread::hardware_concurrency();
    // - 1 serial test
    // - 1 test with nCores + 1 (no improvement expected)
    totalTests = nCores + 2;
    callables.resize(totalTests);
    repeatOutputs.resize(totalTests);
    for (auto& r : repeatOutputs)
        r = 0;
    dts.resize(totalTests);
    for (auto& dt : dts)
        dt = std::chrono::duration<double>::zero();
    std::srand(std::time(NULL));
    for (r = 0; r < REPEAT; ++r) {
        // This data generation dominates the test run time...
        for (i = 0; i < SIZE; ++i)
            input[i] = std::rand();

        // Setup serial test.
        SumArray<dataType> sumArray(input.data(), SIZE, &output);
        callables[0] = &sumArray;

        // Setup parallal tests with different number of threads.
        std::vector<SumArrayParallel<dataType>> sumArrayParallels(totalTests - 1);
        for (std::vector<SumArrayParallel<dataType>>::size_type i = 0; i < sumArrayParallels.size(); ++i) {
            sumArrayParallels[i] = SumArrayParallel<dataType>(input.data(), SIZE, &output, i + 1);
            callables[i + 1] = &sumArrayParallels[i];
        }

        // Run tests.
        for (std::vector<Callable*>::size_type i = 0; i < callables.size(); ++i) {
            start = std::chrono::system_clock::now();
            (*callables[i])();
            end = std::chrono::system_clock::now();
            dts[i] += end - start;
            repeatOutputs[i] += output;
        }
    }
    std::cout << "n cores = " << nCores << std::endl;
    std::cout << "result = " << repeatOutputs[0] << std::endl;
    std::cout << "serial / parallel time (s)" << std::endl;
    for (auto& dt : dts)
        std::cout << dt.count() << std::endl;
    assert(std::adjacent_find(repeatOutputs.begin(), repeatOutputs.end(), std::not_equal_to<int>()) == repeatOutputs.end());
}
