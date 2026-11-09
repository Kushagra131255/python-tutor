// LeetCode 62: Unique Paths
// Difficulty: Medium
// Approach: Use dynamic programming. dp[col] stores the number of ways
// to reach the current row at that column. Each cell combines paths from
// above (the previous dp[col]) and from the left (dp[col - 1]).
// Time: O(M * N) — each cell is updated once.
// Space: O(N) — a single row of DP values is maintained.

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                dp[col] += dp[col - 1];
            }
        }

        return dp[n - 1];
    }
};
