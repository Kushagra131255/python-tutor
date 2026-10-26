// LeetCode 36: Valid Sudoku
// Difficulty: Medium
// Approach: Track digits seen in each row, column, and 3x3 box. Reject any
// repeated digit; '.' cells are ignored.
// Time: O(1) for a fixed 9x9 board | Space: O(1)

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') {
                    continue;
                }

                int digit = ch - '1';
                int box = (r / 3) * 3 + (c / 3);

                if (rows[r][digit] || cols[c][digit] || boxes[box][digit]) {
                    return false;
                }

                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[box][digit] = true;
            }
        }

        return true;
    }
};
