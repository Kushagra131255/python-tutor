// LeetCode 8: String to Integer (atoi)
// Difficulty: Medium
// Approach: Skip leading spaces, parse sign and digits, and clamp before overflow.
// Time: O(n); Space: O(1)
#include <cctype>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = static_cast<int>(s.size());
        while (i < n && s[i] == ' ') ++i;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            ++i;
        }
        long long value = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            value = value * 10 + (s[i] - '0');
            long long signedValue = value * sign;
            if (signedValue > INT_MAX) return INT_MAX;
            if (signedValue < INT_MIN) return INT_MIN;
            ++i;
        }
        return static_cast<int>(value * sign);
    }
};
