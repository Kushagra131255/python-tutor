// LeetCode 28: Find the Index of the First Occurrence in a String
// Difficulty: Easy
// Approach: Use the standard library substring search.
// Time: O(n*m) worst case for straightforward search; Space: O(1) auxiliary
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        return pos == string::npos ? -1 : static_cast<int>(pos);
    }
};
