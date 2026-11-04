// LeetCode 53: Maximum Subarray
// Difficulty: Medium
// Approach: Kadane's algorithm. At each element, either extend the current
// subarray or start a new one, then update the best sum seen so far.
// Time: O(N) — each element is processed once.
// Space: O(1) — only a few variables are used.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int bestSum = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            currentSum = max(nums[i], currentSum + nums[i]);
            bestSum = max(bestSum, currentSum);
        }

        return bestSum;
    }
};
