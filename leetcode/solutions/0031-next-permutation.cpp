// LeetCode 31: Next Permutation
// Difficulty: Medium
// Approach: Find the rightmost ascending pair, swap the pivot with the
// smallest larger value in the suffix, then reverse the suffix to make it
// the smallest possible increasing order.
// Time: O(n) | Space: O(1)

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int pivot = n - 2;

        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
            --pivot;
        }

        if (pivot >= 0) {
            int successor = n - 1;
            while (nums[successor] <= nums[pivot]) {
                --successor;
            }
            swap(nums[pivot], nums[successor]);
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
