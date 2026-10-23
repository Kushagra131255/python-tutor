// LeetCode 6: Zigzag Conversion
// Difficulty: Medium
// Approach: Simulate moving down and diagonally up across the requested rows.
// Time: O(n); Space: O(n) for the output rows
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= static_cast<int>(s.size())) return s;
        vector<string> rows(numRows);
        int row = 0, direction = 1;
        for (char c : s) {
            rows[row] += c;
            if (row == 0) direction = 1;
            else if (row == numRows - 1) direction = -1;
            row += direction;
        }
        string result;
        for (const auto& part : rows) result += part;
        return result;
    }
};
