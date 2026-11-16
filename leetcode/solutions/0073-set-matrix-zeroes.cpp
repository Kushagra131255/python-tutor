#include <vector>
using namespace std;

// LeetCode 73: Set Matrix Zeroes
// Difficulty: Medium
// Approach: Use the first row and column as in-place markers. Save separately
// whether the original first row or first column contains a zero, mark zeroed
// rows/columns from the interior, then apply the markers and saved flags.
// Time: O(m * n) — each matrix cell is visited a constant number of times.
// Space: O(1) auxiliary space.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());

        bool zeroFirstRow = false;
        bool zeroFirstCol = false;

        for (int col = 0; col < cols; ++col) {
            if (matrix[0][col] == 0) {
                zeroFirstRow = true;
                break;
            }
        }

        for (int row = 0; row < rows; ++row) {
            if (matrix[row][0] == 0) {
                zeroFirstCol = true;
                break;
            }
        }

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (zeroFirstRow) {
            for (int col = 0; col < cols; ++col) {
                matrix[0][col] = 0;
            }
        }

        if (zeroFirstCol) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }
    }
};
