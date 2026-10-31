// LeetCode 46: Permutations
// Difficulty: Medium
// Approach: Backtracking. Build each permutation by choosing an unused number.
// A boolean array tracks which elements are already in the current permutation.
// Time: O(N * N!) — there are N! permutations and copying each takes O(N).
// Space: O(N) auxiliary space for the recursion path and used array, excluding output.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<bool>& used,
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (used[i]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            current.pop_back();
            used[i] = false;
        }
    }
};
