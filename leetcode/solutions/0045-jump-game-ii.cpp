// LeetCode 45: Jump Game II
// Difficulty: Medium
// Approach: Greedy. Track the farthest index reachable in the current jump range.
// When the current range ends, take one jump and extend the range.
// Time: O(N) — each array element is visited once.
// Space: O(1) — only a few variables are used.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // Reaching the end of the current jump range means one more jump is needed.
            if (i == currentEnd) {
                ++jumps;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};
