#include <string>
#include <vector>
using namespace std;

// Problem 97: Interleaving String
// Difficulty: Medium
// Approach: One-dimensional dynamic programming. dp[j] indicates whether the
// first i characters of s1 and first j characters of s2 form the corresponding
// prefix of s3. Update left-to-right so dp[j] (previous row) and dp[j-1]
// (current row) provide the two possible transitions.
// Time Complexity: O(m * n), where m = s1.size() and n = s2.size().
// Space Complexity: O(n) for the rolling DP array.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());
        if (m + n != static_cast<int>(s3.size())) {
            return false;
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; ++j) {
                const char target = s3[i + j - 1];
                dp[j] = (dp[j] && s1[i - 1] == target) ||
                        (dp[j - 1] && s2[j - 1] == target);
            }
        }
        return dp[n];
    }
};
