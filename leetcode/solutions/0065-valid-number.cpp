// LeetCode 65: Valid Number
// Difficulty: Hard
// Approach: Scan the string once while tracking whether a digit, decimal point,
// and exponent have appeared. A sign is valid only at the start or after e/E.
// The exponent must have at least one digit after it.
// Time: O(N) — each character is processed once.
// Space: O(1) — only a fixed number of state flags are used.

#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        bool digitAfterExponent = true;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            const char c = s[i];

            if (c >= '0' && c <= '9') {
                seenDigit = true;
                if (seenExponent) {
                    digitAfterExponent = true;
                }
            } else if (c == '+' || c == '-') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (c == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                digitAfterExponent = false;
            } else {
                return false;
            }
        }

        return seenDigit && digitAfterExponent;
    }
};
