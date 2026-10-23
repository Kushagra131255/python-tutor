// LeetCode 26: Remove Duplicates from Sorted Array
// Difficulty: Easy
// Approach: Write each value that differs from the last unique value into the next output slot.
// Time: O(n); Space: O(1)
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        for (int x : nums)
            if (write == 0 || nums[write - 1] != x) nums[write++] = x;
        return write;
    }
};
