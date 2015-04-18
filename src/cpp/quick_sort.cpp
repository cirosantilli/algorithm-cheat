#include <algorithm> // swap
#include <vector>
#include <utility>   // pair

#include "sort.hpp"

/**
Sort the input vector via quick sort.

Same interface as MergeSort.

Worst case time complexity:     $O(input.size() ^ 2)$.

Average case time complexity:   $O(input.size() * log input.size())$.

Extra memory excluding input:   $O(1)$

# Implementation notes

Quicksort is much easier to implement than mergesort.
*/
template<typename COMPARABLE = int>
void quick_sort(std::vector<COMPARABLE>& input) {
    typedef typename std::vector<COMPARABLE>::size_type SizeType;
    SizeType left_begin, left, right, pivot;
    std::vector<std::pair<SizeType,SizeType>> recursion_stack{{0, input.size() - 1}};
    while (!recursion_stack.empty()) {
        std::tie(left_begin, pivot) = recursion_stack.back();
        recursion_stack.pop_back();
        left = left_begin;
        right = left;
        while (right < pivot) {
            if (input[right] < input[pivot]) {
                std::swap(input[left], input[right]);
                left++;
            }
            right++;
        }
        std::swap(input[left], input[pivot]);
        if (left_begin + 1 < left)
            recursion_stack.push_back({left_begin, left - 1});
        if (left + 1 < pivot)
            recursion_stack.push_back({left + 1, pivot});
    }
}

int main(int argc, char **argv) {
    std::vector<int> in = parse_input(argv[1]);
    quick_sort(in);
    print_output(in);
}
