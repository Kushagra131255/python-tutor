// Problem 78: Subsets
// Difficulty: Medium
// Approach: Backtrack from each starting index. Record the current subset,
//           then choose each later element, recurse, and undo the choice.
//           Increasing indices ensure every subset is generated exactly once.
// Time Complexity: O(n * 2^n) — there are 2^n subsets and each copy takes O(n).
// Space Complexity: O(n) auxiliary — current subset and recursion stack,
//                   excluding the returned output (O(n * 2^n)).

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        auto backtrack = [&](auto&& self, int start) -> void {
            result.push_back(current);

            for (int i = start; i < static_cast<int>(nums.size()); ++i) {
                current.push_back(nums[i]);
                self(self, i + 1);
                current.pop_back();
            }
        };

        backtrack(backtrack, 0);
        return result;
    }
};
