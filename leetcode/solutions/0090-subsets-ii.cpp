// LeetCode #90: Subsets II
// Difficulty: Medium
// Approach: Sort the input and backtrack, skipping equal values at the same recursion depth.
// Time Complexity: O(n * 2^n), including the cost of copying each generated subset.
// Space Complexity: O(n) auxiliary space for the recursion stack and current subset, excluding output.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(int start, const vector<int>& nums, vector<int>& current,
                   vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};
