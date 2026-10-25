// LeetCode 34: Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Approach: Run binary search twice: once for the first occurrence and once
// for the last occurrence of target.
// Time: O(log n) | Space: O(1)

#include <vector>
using namespace std;

class Solution {
private:
    int findBound(const vector<int>& nums, int target, bool findFirst) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                answer = mid;
                if (findFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true),
                findBound(nums, target, false)};
    }
};
