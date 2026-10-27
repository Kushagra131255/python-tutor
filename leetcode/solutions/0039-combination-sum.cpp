// LeetCode 39: Combination Sum
// Difficulty: Medium
// Approach: Backtracking. Choose a candidate repeatedly while the remaining target allows it.
// Move to the next candidate after each choice to avoid duplicate combinations.
// Time: Exponential in the worst case; depends on target and candidate values.
// Space: O(target / minCandidate) recursion depth, excluding the output.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            if (candidates[i] > remaining) continue;

            current.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};
