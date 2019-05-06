#include <array>
#include <cassert>
#include <cstdlib>
#include <future>
#include <iomanip>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

typedef uint64_t DataType;

// Single threaded array, iterator version.
template<class T>
typename T::value_type sum_array(
    typename T::const_iterator begin,
    typename T::const_iterator end
) {
    typename T::value_type sum = 0;
    while (begin != end) {
        sum += *begin;
        begin++;
    }
    return sum;
}

template<class T>
void sum_array_index_store(
    const T& array,
    typename T::size_type begin,
    typename T::size_type end,
    typename T::value_type& sum
) {
    while (begin < end) {
        sum += array[begin];
        begin++;
    }
}

// Single threaded array sum, container version.
template<class T>
typename T::value_type sum_array(const T& array) {
    return sum_array<T>(
        array.cbegin(),
        array.cend()
    );
}

template<class T>
void sum_array_store(
    typename T::const_iterator begin,
    typename T::const_iterator end,
    typename T::value_type& sum
) {
    while (begin != end) {
        sum += *begin;
        begin++;
    }
}

// Multi threaded array sum.
template<class T>
typename T::value_type sum_array_parallel(
    const T& array,
    unsigned int nthreads
) {
    auto size = array.size();
    auto actual_nthreads = std::min(
        size,
        (decltype(array.size()))nthreads
    );
    auto delta = size / actual_nthreads;
    auto it = array.cbegin();
    typename T::value_type sum = 0;

#if 1
    std::vector<std::future<DataType>> futures;
    for (decltype(actual_nthreads) i = 0; i < actual_nthreads; ++i) {
        futures.push_back(std::async(
            std::launch::async,
            [it, delta]{return sum_array<T>(it, it + delta);}
        ));
#if 0
        // TODO why this doesn't this syntax work? I can't be bothered right now.
        futures.push_back(std::async(
            std::launch::async,
            sum_array<T>,
            it,
            it + delta
        ));
#endif
        it += delta;
    }
    for (auto& future : futures) {
        sum += future.get();
    }
#endif

#if 0
    std::vector<std::future<DataType>> futures;
    for (decltype(actual_nthreads) i = 0; i < actual_nthreads; ++i) {
        futures.push_back(std::async(
            std::launch::async,
            [i,delta]{
                return sum_array<T>(i * delta, (i+1) * delta);
            }
        ));
        it += delta;
    }
    for (auto& future : futures) {
        sum += future.get();
    }
    for (auto& future : futures) {
        sum += future.get();
    }
#endif

#if 0
    std::vector<std::thread> threads(actual_nthreads);
    std::vector<typename T::value_type> outputs(actual_nthreads);
    for (decltype(actual_nthreads) i = 0; i < actual_nthreads; ++i) {
        threads[i] = std::thread(
            sum_array_store<T>,
            it,
            it + delta,
            std::ref(outputs[i])
        );
        it += delta;
    }
    for (decltype(actual_nthreads) i = 0; i < actual_nthreads; ++i) {
        threads[i].join();
        sum += outputs[i];
    }
#endif

#if 0
    std::vector<std::thread> threads(actual_nthreads);
    std::vector<typename T::value_type> outputs(actual_nthreads);
    for (decltype(actual_nthreads) i = 0; i < actual_nthreads; ++i) {
        threads[i] = std::thread(
            sum_array_index_store<T>,
            std::ref(array),
            i * delta,
            (i + 1) * delta,
            std::ref(outputs[i])
        );
        it += delta;
    }
    for (decltype(actual_nthreads) i = 0; i < actual_nthreads; ++i) {
        threads[i].join();
        sum += outputs[i];
    }
#endif

    return sum + sum_array<T>(it, array.cend());
}

void print_result(std::chrono::duration<double> dt, unsigned int nthreads) {
    std::cout
        << std::setprecision(4)
        << std::fixed
        << nthreads
        << " "
        << std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>(dt).count()
        << std::endl
    ;
}

int main(int argc, char **argv) {
    unsigned long long nelems;
    if (argc > 1) {
        nelems = std::strtoll(argv[1], NULL, 10);
    } else {
        nelems = 10;
    }

    // Initialize array with random numbers.
    std::vector<DataType> elems(nelems);
    std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<decltype(rng)::result_type> dist(
        0,
        std::numeric_limits<DataType>::max()
    );
    for (auto& i : elems) {
        i = dist(rng);
        i = 1;
    }

    // Single threaded sanity check.
    auto start = std::chrono::steady_clock::now();
    auto serial_result = sum_array(elems);
    auto end = std::chrono::steady_clock::now();
    print_result(end - start, 0);

    // Use different number of threads.
    auto max_nthreads = std::thread::hardware_concurrency() * 2;
    for (decltype(max_nthreads) nthreads = 1; nthreads <= max_nthreads; ++nthreads) {
        auto start = std::chrono::steady_clock::now();
        auto result = sum_array_parallel(elems, nthreads);
        auto end = std::chrono::steady_clock::now();
        print_result(end - start, nthreads);
        // Sanity check that our implementation is correct.
        assert(result == serial_result);
    }
}
