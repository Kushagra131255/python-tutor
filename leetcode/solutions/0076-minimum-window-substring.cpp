#include <array>
#include <limits>
#include <string>
using namespace std;

// LeetCode #76: Minimum Window Substring
// Difficulty: Hard
// Approach: Sliding window with a frequency table. Expand the right edge until
//           all target characters are covered, then shrink from the left to
//           keep the smallest valid window seen so far.
// Time Complexity: O(m + n) - each pointer moves across its string at most once.
// Space Complexity: O(1) - a fixed-size frequency table for byte characters.
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) {
            return "";
        }

        array<int, 256> need{};
        for (unsigned char ch : t) {
            ++need[ch];
        }

        size_t missing = t.size();
        size_t left = 0;
        size_t bestStart = 0;
        size_t bestLength = numeric_limits<size_t>::max();

        for (size_t right = 0; right < s.size(); ++right) {
            unsigned char entering = static_cast<unsigned char>(s[right]);
            if (need[entering] > 0) {
                --missing;
            }
            --need[entering];

            while (missing == 0) {
                size_t windowLength = right - left + 1;
                if (windowLength < bestLength) {
                    bestLength = windowLength;
                    bestStart = left;
                }

                unsigned char leaving = static_cast<unsigned char>(s[left]);
                ++need[leaving];
                if (need[leaving] > 0) {
                    ++missing;
                }
                ++left;
            }
        }

        return bestLength == numeric_limits<size_t>::max()
                   ? ""
                   : s.substr(bestStart, bestLength);
    }
};
