// LeetCode 27: Remove Element
// Difficulty: Easy
// Approach: Overwrite the front of the array with values not equal to val.
// Time: O(n); Space: O(1)
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        for (int x : nums) if (x != val) nums[write++] = x;
        return write;
    }
};
