#include <vector>
using namespace std;

// LeetCode #80: Remove Duplicates from Sorted Array II
// Difficulty: Medium
// Approach: Keep a write pointer and allow a value only when it differs
// from the value two positions behind the write pointer. This retains at
// most two copies of each value in-place.
// Time: O(n) — each input element is examined once.
// Space: O(1) — in-place updates with constant extra storage.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        for (int value : nums) {
            if (write < 2 || value != nums[write - 2]) {
                nums[write++] = value;
            }
        }
        return write;
    }
};
