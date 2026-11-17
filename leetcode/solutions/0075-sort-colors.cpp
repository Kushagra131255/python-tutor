#include <utility>
#include <vector>
using namespace std;

// LeetCode #75: Sort Colors
// Difficulty: Medium
// Approach: Dutch National Flag algorithm with low, mid, and high pointers.
//           Partition the array into 0s, 1s, and 2s in one pass.
// Time Complexity: O(n) - each element is examined at most once.
// Space Complexity: O(1) - in-place swaps with constant extra variables.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                ++low;
                ++mid;
            } else if (nums[mid] == 1) {
                ++mid;
            } else {
                swap(nums[mid], nums[high]);
                --high;
            }
        }
    }
};
