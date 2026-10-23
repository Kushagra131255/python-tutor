// LeetCode 10: Regular Expression Matching
// Difficulty: Hard
// Approach: Dynamic programming: '.' matches any character; '*' means zero or more of its preceding token.
// Time: O(m*n); Space: O(m*n)
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = static_cast<int>(s.size()), n = static_cast<int>(p.size());
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= n; ++j)
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*' && j >= 2) {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
