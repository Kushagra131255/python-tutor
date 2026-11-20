#include <algorithm>
#include <vector>
using namespace std;

// LeetCode 85: Maximal Rectangle
// Difficulty: Hard
// Approach: Build histogram heights for each row and use a monotonic stack
//           to find the largest rectangle in each histogram.
// Time Complexity: O(rows * cols)
// Space Complexity: O(cols) auxiliary space for heights and the stack.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        vector<int> heights(cols + 1, 0); // Extra zero-height sentinel.
        int best = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
            }

            vector<int> st;
            st.reserve(cols + 1);
            for (int c = 0; c <= cols; ++c) {
                while (!st.empty() && heights[st.back()] > heights[c]) {
                    const int height = heights[st.back()];
                    st.pop_back();
                    const int leftSmaller = st.empty() ? -1 : st.back();
                    const int width = c - leftSmaller - 1;
                    best = max(best, height * width);
                }
                st.push_back(c);
            }
        }

        return best;
    }
};
