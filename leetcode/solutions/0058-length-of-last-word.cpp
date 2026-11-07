// LeetCode 58: Length of Last Word
// Difficulty: Easy
// Approach: Scan from the end. Skip trailing spaces, then count characters
// until the beginning of the last word is reached.
// Time: O(N) — in the worst case, the string is scanned once.
// Space: O(1) — only an index and a counter are used.

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = static_cast<int>(s.size()) - 1;

        // Ignore spaces at the end of the string.
        while (i >= 0 && s[i] == ' ') {
            --i;
        }

        int length = 0;

        // Count characters in the last word.
        while (i >= 0 && s[i] != ' ') {
            ++length;
            --i;
        }

        return length;
    }
};
