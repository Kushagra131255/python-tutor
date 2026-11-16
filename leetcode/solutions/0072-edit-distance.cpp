#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// LeetCode #72: Edit Distance
// Difficulty: Medium
// Approach: Use a 2D DP table where dp[i][j] is the minimum number of
// operations to convert the first i characters of word1 into the first j
// characters of word2. Matching characters take the diagonal value; otherwise
// choose the cheapest insert, delete, or replace operation.
// Time Complexity: O(m * n), where m and n are the lengths of the two words.
// Space Complexity: O(m * n) for the DP table.
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = static_cast<int>(word1.size());
        const int n = static_cast<int>(word2.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        return dp[m][n];
    }
};
