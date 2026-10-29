// LeetCode 42: Trapping Rain Water
// Difficulty: Hard
// Approach: Two pointers. Process the side with the smaller height;
// its water level is bounded by the maximum height seen from that side.
// Time: O(N) — each pointer moves inward at most N times.
// Space: O(1) extra space.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                ++left;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                --right;
            }
        }

        return water;
    }
};
