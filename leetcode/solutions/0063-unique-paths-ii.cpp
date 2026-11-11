// LeetCode 63: Unique Paths II
// Difficulty: Medium
// Approach: Use one-dimensional dynamic programming. An obstacle resets
// the number of paths to zero. Otherwise, add paths from the left to the
// paths from above, stored in the current dp[col] value.
// Time: O(M * N) — each grid cell is processed once.
// Space: O(N) — one DP array is used.

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = static_cast<int>(obstacleGrid.size());
        int n = static_cast<int>(obstacleGrid[0].size());

        vector<int> dp(n, 0);
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (obstacleGrid[row][col] == 1) {
                    dp[col] = 0;
                } else if (col > 0) {
                    dp[col] += dp[col - 1];
                }
            }
        }

        return dp[n - 1];
    }
};
