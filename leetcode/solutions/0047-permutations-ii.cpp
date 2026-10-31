// LeetCode 47: Permutations II
// Difficulty: Medium
// Approach: Sort the input, then use backtracking with a used array.
// Skip an equal value when its previous copy has not been used in this path;
// this prevents generating duplicate permutations.
// Time: O(N * N!) worst case, including copying each permutation.
// Space: O(N) auxiliary space for recursion and the used array, excluding output.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

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

            // Only use this copy if the previous equal copy is already in the path.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            current.pop_back();
            used[i] = false;
        }
    }
};
