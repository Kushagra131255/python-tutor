// LeetCode 55: Jump Game
// Difficulty: Medium
// Approach: Greedy. Track the farthest index reachable so far. If the current
// index is beyond that boundary, the last index cannot be reached.
// Time: O(N) — each array element is visited at most once.
// Space: O(1) — only a few variables are used.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i > farthest) {
                return false;
            }

            farthest = max(farthest, i + nums[i]);
            if (farthest >= static_cast<int>(nums.size()) - 1) {
                return true;
            }
        }

        return true;
    }
};
