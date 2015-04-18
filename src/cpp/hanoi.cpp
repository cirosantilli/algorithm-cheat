#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl
#include <tuple>
#include <vector>
#include <utility>      // pair

/**
Solve the classic Hanoi problem starting from any of the 3 pegs `from`
and ending at any of the 3 pegs `to` in the minimum ammont of moves.
*/
template<typename INPUT_TYPE>
void hanoi(int n_disks, int from, int to,
        std::vector<std::pair<INPUT_TYPE,INPUT_TYPE>>& output) {
    if (from != to) {
        if (n_disks == 1) {
            output.push_back(std::pair<int,int>{from,to});
            return;
        } else {
            int other = 3 - to - from;
            hanoi(n_disks - 1, from, other, output);
            output.push_back(std::pair<int,int>{from,to});
            hanoi(n_disks - 1, other, to, output);
        }
    } else {
        return;
    }
}

int main() {
    typedef std::vector<std::pair<int,int>> OutputType;
    typedef std::tuple<int, int, int, OutputType> IO;
    IO in_outs[]{
        // One moves.
        IO{1, 0, 1, {{0, 1}}},
        IO{1, 0, 2, {{0, 2}}},
        IO{1, 1, 2, {{1, 2}}},
        IO{2, 0, 1, {{0, 2}, {0, 1}, {2, 1}}},
        IO{2, 0, 2, {{0, 1}, {0, 2}, {1, 2}}},
        IO{3, 0, 1, {
            {0, 1}, {0, 2}, {1, 2},
            {0, 1}, {2, 0}, {2, 1},
            {0, 1}
        }},
        // Edge case: move to self.
        IO{1, 0, 0, {}},
        IO{2, 0, 0, {}},
    };
    for (auto& in_out : in_outs) {
        OutputType output;
        auto& n_disks         = std::get<0>(in_out);
        auto& from            = std::get<1>(in_out);
        auto& to              = std::get<2>(in_out);
        auto& expected_output = std::get<3>(in_out);
        hanoi(n_disks, from, to, output);
        assert(output == expected_output);
    }
}
