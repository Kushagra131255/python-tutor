// LeetCode 52: N-Queens II
// Difficulty: Hard
// Approach: Backtracking. Place one queen per row and track occupied columns
// and diagonals; count each complete valid board without storing the boards.
// Time: O(N!) upper bound — explores valid column placements row by row.
// Space: O(N) auxiliary space for the column and diagonal tracking arrays
// and recursion stack.

#include <vector>
using namespace std;

class Solution {
private:
    int n;
    int total;
    vector<bool> usedColumns;
    vector<bool> usedMainDiagonals;
    vector<bool> usedAntiDiagonals;

    void backtrack(int row) {
        if (row == n) {
            ++total;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int mainDiagonal = row - col + n - 1;
            int antiDiagonal = row + col;

            if (usedColumns[col] || usedMainDiagonals[mainDiagonal] ||
                usedAntiDiagonals[antiDiagonal]) {
                continue;
            }

            usedColumns[col] = true;
            usedMainDiagonals[mainDiagonal] = true;
            usedAntiDiagonals[antiDiagonal] = true;

            backtrack(row + 1);

            // Backtrack: free the column and both diagonals.
            usedColumns[col] = false;
            usedMainDiagonals[mainDiagonal] = false;
            usedAntiDiagonals[antiDiagonal] = false;
        }
    }

public:
    int totalNQueens(int size) {
        n = size;
        total = 0;
        usedColumns.assign(n, false);
        usedMainDiagonals.assign(2 * n - 1, false);
        usedAntiDiagonals.assign(2 * n - 1, false);

        backtrack(0);
        return total;
    }
};
