#include <algorithm>

// LeetCode #70: Climbing Stairs
// Difficulty: Easy
// Approach: Use two rolling Fibonacci values; each step is the sum of the
//          ways to reach the previous two steps.
// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary space
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int twoStepsBack = 1;
        int oneStepBack = 2;

        for (int step = 3; step <= n; ++step) {
            const int current = oneStepBack + twoStepsBack;
            twoStepsBack = oneStepBack;
            oneStepBack = current;
        }

        return oneStepBack;
    }
};
