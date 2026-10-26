// LeetCode 35: Search Insert Position
// Difficulty: Easy
// Approach: Binary search for target. If it is absent, the lower-bound index
// (the first position with a value >= target) is its insertion position.
// Time: O(log n) | Space: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size());

        // Search the half-open range [left, right).
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
