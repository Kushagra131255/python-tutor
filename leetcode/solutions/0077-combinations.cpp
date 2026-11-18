// Problem 77: Combinations
// Difficulty: Medium
// Approach: Backtrack by choosing values in increasing order. Prune a branch
//           when the remaining range cannot fill the combination.
// Time Complexity: O(k * C(n, k)) — copy each of the C(n, k) results of size k.
// Space Complexity: O(k) auxiliary — recursion stack and current combination,
//                   excluding the returned output (O(k * C(n, k))).

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        auto backtrack = [&](auto&& self, int start) -> void {
            if (static_cast<int>(current.size()) == k) {
                result.push_back(current);
                return;
            }

            const int needed = k - static_cast<int>(current.size());
            // No valid completion exists beyond this upper bound.
            for (int value = start; value <= n - needed + 1; ++value) {
                current.push_back(value);
                self(self, value + 1);
                current.pop_back();
            }
        };

        backtrack(backtrack, 1);
        return result;
    }
};
