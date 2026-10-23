// LeetCode 16: 3Sum Closest
// Difficulty: Medium
// Approach: Sort and use two pointers for each fixed first element.
// Time: O(n^2); Space: O(1) auxiliary excluding sorting
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            int l = i + 1, r = static_cast<int>(nums.size()) - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(best - target)) best = sum;
                if (sum < target) ++l;
                else if (sum > target) --r;
                else return sum;
            }
        }
        return best;
    }
};
