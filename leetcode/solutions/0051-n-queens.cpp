// LeetCode 51: N-Queens
// Difficulty: Hard
// Approach: Backtracking. Place one queen per row and track occupied columns
// and diagonals to reject attacking positions in constant time.
// Time: O(N!) — backtracking explores valid column placements row by row (upper bound).
// Space: O(N) auxiliary space for the column and diagonal tracking arrays,
// excluding the board and the returned solutions.

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string>> answers;
    vector<string> board;
    vector<bool> usedColumns;
    vector<bool> usedMainDiagonals;
    vector<bool> usedAntiDiagonals;
    int n;

    void backtrack(int row) {
        if (row == n) {
            answers.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int mainDiagonal = row - col + n - 1;
            int antiDiagonal = row + col;

            if (usedColumns[col] || usedMainDiagonals[mainDiagonal] ||
                usedAntiDiagonals[antiDiagonal]) {
                continue;
            }

            board[row][col] = 'Q';
            usedColumns[col] = true;
            usedMainDiagonals[mainDiagonal] = true;
            usedAntiDiagonals[antiDiagonal] = true;

            backtrack(row + 1);

            // Undo the placement before trying the next column.
            board[row][col] = '.';
            usedColumns[col] = false;
            usedMainDiagonals[mainDiagonal] = false;
            usedAntiDiagonals[antiDiagonal] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int size) {
        n = size;
        answers.clear();
        board.assign(n, string(n, '.'));
        usedColumns.assign(n, false);
        usedMainDiagonals.assign(2 * n - 1, false);
        usedAntiDiagonals.assign(2 * n - 1, false);

        backtrack(0);
        return answers;
    }
};
