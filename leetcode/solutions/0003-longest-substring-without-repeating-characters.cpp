// LeetCode 3: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Approach: Sliding window; jump the left edge past a repeated character's last index.
// Time: O(n); Space: O(min(n, character-set size))
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int left = 0, best = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            left = max(left, last[c] + 1);
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
