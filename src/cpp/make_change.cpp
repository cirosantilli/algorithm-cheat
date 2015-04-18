#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl

void vector_sum(const std::vector<int>& v0, const std::vector<int>& v1,
        std::vector<int>& output) {
    output.resize(v0.size());
    for (std::vector<int>::size_type i = 0; i < v0.size(); ++i)
        output[i] = v0[i] + v1[i];
}

/**
Solve the change making problem via dynamic programming.

Worst case time complexity: $O(output.size() ^ 3)$. TODO check. It is \sum i^2. Does that make i^3?

Given a value `total`, choose the minimum ammount of coins
with one of the values inside `coin_values` that sums up to exactly `total`.

@param[in] coin_values  The value of each type of coin. Must be already ordered.
                        All values must be positive.
@param[in] total        The total value that must be reached with the coins.
                        Must be positive.
@param[out] output      The solution, that is, how many of each type of coin is needed to attain the total.

    If the total is not attainable, this container shall be empty.
*/
void make_change(const std::vector<int>& coin_values, int total, std::vector<int>& output) {
    std::vector<bool> possible(total + 1, false);
    std::vector<int> coin_counts(total + 1, std::numeric_limits<int>::max());
    std::vector<std::vector<int> > solutions(total + 1, std::vector<int>(coin_values.size(), 0));
    possible[0] = true;
    coin_counts[0] = 0;
    for (std::vector<int>::size_type i = 0; i < coin_values.size(); ++i) {
        int coin_value = coin_values[i];
        possible[coin_value] = true;
        solutions[coin_value][i] = 1;
        coin_counts[coin_value] = 1;
    }
    for (int subtotal = 1; subtotal <= total; ++subtotal) {
        int min_coin_count = coin_counts[subtotal];
        int best_first, best_second;
        bool cur_possible = false;
        for (int first = 0; first <= subtotal / 2; ++first) {
            int second = subtotal - first;
            if (possible[first] && possible[second]) {
                int new_coin_count = coin_counts[first] + coin_counts[second];
                if (new_coin_count < min_coin_count) {
                    best_first = first;
                    best_second = second;
                    min_coin_count = new_coin_count;
                    cur_possible = true;
                }
            }
        }
        if (cur_possible) {
            possible[subtotal] = true;
            coin_counts[subtotal] = coin_counts[best_first]
                + coin_counts[best_second];
            vector_sum(solutions[best_first], solutions[best_second], solutions[subtotal]);
        }
    }
    output = solutions[total];
}

int main() {
    typedef std::tuple<std::vector<int>,
                       int,
                       std::vector<int>> InOut;

    InOut in_outs[]{
        InOut{
            {1, 3, 4},
            6,
            {0, 2, 0}
        },
        InOut{
            {1, 3, 4, 7, 11, 24},
            1731,
            {0, 1, 0, 0, 0, 72}
        },
    };
    for (auto& in_out : in_outs) {
        auto& coin_values = std::get<0>(in_out);
        auto& total  = std::get<1>(in_out);
        auto& expected_output = std::get<2>(in_out);
        std::vector<int> output;
        make_change(coin_values, total, output);
        assert(output == expected_output);
    }
}
