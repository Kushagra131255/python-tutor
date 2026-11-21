// LeetCode #88: Merge Sorted Array
// Difficulty: Easy
// Approach: Merge from right to left so unread values in nums1 are not overwritten.
// Time Complexity: O(m + n)
// Space Complexity: O(1) auxiliary space.

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int write = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[write--] = nums1[i--];
            } else {
                nums1[write--] = nums2[j--];
            }
        }
    }
};
