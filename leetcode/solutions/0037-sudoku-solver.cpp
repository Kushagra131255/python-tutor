// LeetCode 37: Sudoku Solver
// Difficulty: Hard
// Approach: Backtracking. Track digits already used in each row, column, and 3x3 box.
// Try each valid digit in an empty cell; recurse, and undo the choice if it fails.
// Time: O(9^m) worst case, where m is the number of empty cells.
// Space: O(m) recursion stack in the worst case.

#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                int digit = board[r][c] - '1';
                int box = (r / 3) * 3 + c / 3;
                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[box][digit] = true;
            }
        }

        solve(board, rows, cols, boxes);
    }

private:
    bool solve(vector<vector<char>>& board, bool rows[9][9],
               bool cols[9][9], bool boxes[9][9]) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') continue;

                int box = (r / 3) * 3 + c / 3;
                for (int digit = 0; digit < 9; ++digit) {
                    if (rows[r][digit] || cols[c][digit] || boxes[box][digit])
                        continue;

                    board[r][c] = char('1' + digit);
                    rows[r][digit] = cols[c][digit] = boxes[box][digit] = true;

                    if (solve(board, rows, cols, boxes)) return true;

                    board[r][c] = '.';
                    rows[r][digit] = cols[c][digit] = boxes[box][digit] = false;
                }
                return false;
            }
        }
        return true;
    }
};
