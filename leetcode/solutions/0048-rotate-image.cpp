// LeetCode 48: Rotate Image
// Difficulty: Medium
// Approach: Transpose the matrix, then reverse each row to rotate it 90 degrees clockwise.
// Time: O(N^2) — every matrix element is processed a constant number of times.
// Space: O(1) extra space — the matrix is modified in place.

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());

        // Transpose the matrix across its main diagonal.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row to finish the clockwise rotation.
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
