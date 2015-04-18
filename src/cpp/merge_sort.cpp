#include <algorithm>    // copy
#include <cmath>        // pow, ceil
#include <vector>

#include "sort.hpp"

/**
Sort the input vector via merge sort inline.

Time complexity: $O(input.size() log input.size())$

Memory complexity excluding input: $O(input.size())$

@parm[in,out]  input      The input vector to be sorted. It shall be modified to contain the output.
@tparm         COMPARABLE A type that supports operators `<` and `==`.
*/
template<typename COMPARABLE = int>
void merge_sort(std::vector<COMPARABLE>& input) {
    typename std::vector<COMPARABLE>::size_type input_size,
             current_size,
             left0,
             right0,
             left1,
             right1,
             output_position,
             size_pow2;
    typename std::vector<COMPARABLE>::iterator output_begin;
    auto input_begin = input.begin();
    input_size = input.size();
    std::vector<COMPARABLE> output(input_size);
    if (input_size < 2)
        return;
    size_pow2 = std::pow(2, std::ceil(std::log2(input_size)));
    current_size = 1;
    output_begin = output.begin();
    while (current_size <= size_pow2 / 2) {
        output_position = 0;
        while (output_position < input_size) {
            left0  = output_position;
            right0 = left0  + current_size;
            left1  = right0;
            right1 = right0 + current_size;
            // Make corrections in case the input size is not a power of 2.
            if (right0 > input_size) {
                right0 = input_size;
                // If left1 == right1, no data access is ever made on the right side.
                // This is what we want since the right side is completely out of range in this case.
                left1 = right1;
            } else if (right1 > input_size) {
                right1 = input_size;
            }
            while (true) {
                if (left0 == right0) {
                    std::copy(input_begin + left1, input_begin + right1, output_begin + output_position);
                    output_position += right1 - left1;
                    break;
                } else if (left1 == right1) {
                    std::copy(input_begin + left0, input_begin + right0, output_begin + output_position);
                    output_position += right0 - left0;
                    break;
                }
                if (input[left0] < input[left1]) {
                    output[output_position] = input[left0];
                    left0++;
                } else {
                    output[output_position] = input[left1];
                    left1++;
                }
                output_position++;
            }
        }
        input = output;
        current_size *= 2;
    }
}

int main(int argc, char **argv) {
    std::vector<int> input = parse_input(argv[1]);
    merge_sort(input);
    print_output(input);
}
