#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl
#include <tuple>
#include <vector>

/**
Calculate the [longest common subsequence](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)
between two strings.

The substrings do not need to be contiguous.

@param[in]  input0, input1  The input strings.
@param[out] output          The longest substring.

    In case that there are multiple possible outputs

@tparam T The data type of the values of each string. Must implement `==`.
*/
template<typename T>
void longest_common_subsequence(
        const std::vector<T>& input0,
        const std::vector<T>& input1,
        std::vector<typename std::vector<T>::size_type>& output) {
    typedef typename std::vector<T>::size_type SizeType;
    typedef char PreviousDirectionType;
    const PreviousDirectionType kUp   = 0;
    const PreviousDirectionType kLeft = 1;
    const PreviousDirectionType kDiag = 2;
    SizeType input0_size = input0.size();
    SizeType input1_size = input1.size();
    std::vector<std::vector<PreviousDirectionType>> previous(
            input0_size + 1, std::vector<PreviousDirectionType>(input1_size + 1));
    std::vector<SizeType> length_cur(input1_size + 1, 0);
    std::vector<SizeType> length_prev(input1_size + 1, 0);
    SizeType i, j;
    for (i = 1; i <= input0_size; ++i) {
        for (j = 1; j <= input1_size; ++j) {
            if (input0[i - 1] == input1[j - 1]) {
                previous[i][j] = kDiag;
                length_cur[j]  = length_prev[j - 1] + 1;
            } else {
                if (length_cur[j - 1] < length_prev[j]) {
                    previous[i][j] = kUp;
                    length_cur[j]  = length_prev[j];
                } else {
                    previous[i][j] = kLeft;
                    length_cur[j]  = length_cur[j - 1];
                }
            }
        }
        length_prev = length_cur;
    }
    output = std::vector<SizeType>(length_cur[input1_size]);
    i = input0_size;
    j = input1_size;
    auto it = output.rbegin();
    while (it != output.rend()) {
        switch (previous[i][j]) {
            case kLeft: {
                --j;
                break;
            }
            case kUp: {
                --i;
                break;
            }
            case kDiag: {
                *it = input0[i - 1];
                ++it;
                --i;
                --j;
                break;
            }
        }
    }
}

int main() {
    typedef int InputType;
    typedef std::vector<std::vector<InputType>::size_type> OutputType;
    typedef std::tuple<std::vector<InputType>,
                       std::vector<InputType>,
                       OutputType> IO;
    IO in_outs[]{
        IO{
            {0},
            {0},
            {0},
        },
        IO{
            {0},
            {1},
            {},
        },
        IO{
            {2, 0, 1},
            {0, 2, 1, 0, 3},
            {0, 1},
        },
    };
    OutputType output;
    for (auto& in_out : in_outs) {
        auto& input0           = std::get<0>(in_out);
        auto& input1           = std::get<1>(in_out);
        auto& expected_output  = std::get<2>(in_out);
        longest_common_subsequence(input0, input1, output);
        assert(output == expected_output);
    }
}
