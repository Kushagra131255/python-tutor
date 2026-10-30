// LeetCode 44: Wildcard Matching
// Difficulty: Hard
// Approach: Dynamic programming with a 1D array.
// '*' matches any sequence (including empty), while '?' matches one character.
// Time: O(M * N), where M and N are the lengths of s and p.
// Space: O(N) for the DP array.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(p.size());

        // dp[j] means the processed prefix of s matches the first j pattern characters.
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // An initial run of '*' characters can match an empty string.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            } else {
                break;
            }
        }

        for (int i = 1; i <= m; ++i) {
            bool diagonal = dp[0];
            dp[0] = false;

            for (int j = 1; j <= n; ++j) {
                bool oldUp = dp[j];

                if (p[j - 1] == '*') {
                    // '*' either matches nothing (dp[j - 1]) or consumes one more character (old dp[j]).
                    dp[j] = dp[j] || dp[j - 1];
                } else {
                    // A literal or '?' consumes exactly one matching character.
                    dp[j] = (p[j - 1] == '?' || p[j - 1] == s[i - 1]) && diagonal;
                }

                diagonal = oldUp;
            }
        }

        return dp[n];
    }
};
