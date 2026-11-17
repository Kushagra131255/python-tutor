#include <vector>
using namespace std;

// LeetCode #74 - Search a 2D Matrix
// Difficulty: Medium
// Approach: Treat the row-major matrix as one sorted array and binary-search
// its virtual indices. Map index i to matrix[i / cols][i % cols].
// Time: O(log(m * n)); Space: O(1) auxiliary.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = static_cast<int>(matrix.size());
        if (rows == 0 || matrix[0].empty()) {
            return false;
        }

        const int cols = static_cast<int>(matrix[0].size());
        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            const int mid = left + (right - left) / 2;
            const int value = matrix[mid / cols][mid % cols];

            if (value == target) {
                return true;
            }
            if (value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
