#include <vector>
using namespace std;

// LeetCode #81: Search in Rotated Sorted Array II
// Difficulty: Medium
// Approach: Binary search on the rotated array. If one half is strictly
// ordered, keep that half only when it can contain the target. When the
// left, middle, and right values are equal, shrink both ends because
// duplicates hide which half is ordered.
// Time: O(n) worst case with many duplicates; O(log n) when halves can be
// consistently distinguished.
// Space: O(1) — iterative search uses constant extra storage.
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) {
                // The left half is sorted.
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // The right half is sorted.
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
