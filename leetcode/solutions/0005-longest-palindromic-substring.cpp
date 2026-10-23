// LeetCode 5: Longest Palindromic Substring
// Difficulty: Medium
// Approach: Expand around every odd and even palindrome center.
// Time: O(n^2); Space: O(1) auxiliary
#include <string>
using namespace std;

class Solution {
    void expand(const string& s, int left, int right, int& start, int& best) {
        while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right]) {
            --left; ++right;
        }
        int len = right - left - 1;
        if (len > best) { best = len; start = left + 1; }
    }
public:
    string longestPalindrome(string s) {
        int start = 0, best = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            expand(s, i, i, start, best);
            expand(s, i, i + 1, start, best);
        }
        return s.substr(start, best);
    }
};
