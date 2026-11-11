// LeetCode 64: Minimum Path Sum
// Difficulty: Medium
// Approach: Use the grid itself for dynamic programming. Each cell stores
// its own value plus the minimum of the path sum from above or from the left.
// The first row and column naturally accumulate their only possible paths.
// Time: O(M * N) — each cell is processed once.
// Space: O(1) auxiliary — the input grid is updated in place.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row == 0 && col == 0) {
                    continue;
                }

                if (row == 0) {
                    grid[row][col] += grid[row][col - 1];
                } else if (col == 0) {
                    grid[row][col] += grid[row - 1][col];
                } else {
                    grid[row][col] += min(grid[row - 1][col],
                                          grid[row][col - 1]);
                }
            }
        }

        return grid[m - 1][n - 1];
    }
};
