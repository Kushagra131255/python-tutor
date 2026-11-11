// LeetCode 59: Spiral Matrix II
// Difficulty: Medium
// Approach: Fill the matrix layer by layer in clockwise spiral order.
// Maintain top, bottom, left, and right boundaries, shrinking each after
// completing its corresponding edge.
// Time: O(N^2) — every matrix cell is filled exactly once.
// Space: O(1) auxiliary — excluding the O(N^2) output matrix.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int value = 1;

        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = value++;
            }
            ++top;

            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = value++;
            }
            --right;

            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = value++;
                }
                --bottom;
            }

            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = value++;
                }
                ++left;
            }
        }

        return matrix;
    }
};
