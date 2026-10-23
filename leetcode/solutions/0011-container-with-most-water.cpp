// LeetCode 11: Container With Most Water
// Difficulty: Medium
// Approach: Two pointers; move the shorter side because it limits the area.
// Time: O(n); Space: O(1)
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = static_cast<int>(height.size()) - 1, best = 0;
        while (l < r) {
            best = max(best, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return best;
    }
};
