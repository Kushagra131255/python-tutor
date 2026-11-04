// LeetCode 54: Spiral Matrix
// Difficulty: Medium
// Approach: Maintain top, bottom, left, and right boundaries. Traverse each
// boundary in spiral order, shrinking it after every completed direction.
// Time: O(M * N) — every matrix element is visited exactly once.
// Space: O(1) auxiliary space, excluding the returned vector.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int top = 0;
        int bottom = static_cast<int>(matrix.size()) - 1;
        int left = 0;
        int right = static_cast<int>(matrix[0].size()) - 1;

        while (top <= bottom && left <= right) {
            // Traverse the top row from left to right.
            for (int col = left; col <= right; ++col) {
                result.push_back(matrix[top][col]);
            }
            ++top;

            // Traverse the right column from top to bottom.
            for (int row = top; row <= bottom; ++row) {
                result.push_back(matrix[row][right]);
            }
            --right;

            // Traverse the bottom row from right to left, if it remains.
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    result.push_back(matrix[bottom][col]);
                }
                --bottom;
            }

            // Traverse the left column from bottom to top, if it remains.
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    result.push_back(matrix[row][left]);
                }
                ++left;
            }
        }

        return result;
    }
};
