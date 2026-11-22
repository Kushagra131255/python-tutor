// LeetCode #91: Decode Ways
// Difficulty: Medium
// Approach: Use rolling DP states for the number of decodings ending before the
// current and previous characters; add valid one-digit and two-digit choices.
// Time Complexity: O(n), where n is the length of the input string.
// Space Complexity: O(1) auxiliary space.

#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int twoBack = 1;
        int oneBack = 1;

        for (int i = 1; i < static_cast<int>(s.size()); ++i) {
            int current = 0;

            if (s[i] != '0') {
                current += oneBack;
            }

            const int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += twoBack;
            }

            twoBack = oneBack;
            oneBack = current;
        }

        return oneBack;
    }
};
