// LeetCode 40: Combination Sum II
// Difficulty: Medium
// Approach: Sort candidates, then backtrack. Each element may be used once;
// skip equal values at the same recursion depth to avoid duplicate combinations.
// Time: O(2^N) worst case, excluding the cost of storing results.
// Space: O(N) for recursion and the current combination, excluding output.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int remaining, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > remaining) break;

            current.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
};
