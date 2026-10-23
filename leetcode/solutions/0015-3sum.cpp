// LeetCode 15: 3Sum
// Difficulty: Medium
// Approach: Sort, fix one number, then use two pointers while skipping duplicates.
// Time: O(n^2); Space: O(1) auxiliary excluding sorting
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;
            int l = i + 1, r = n - 1;
            while (l < r) {
                long long sum = 1LL * nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int a = nums[l], b = nums[r];
                    while (l < r && nums[l] == a) ++l;
                    while (l < r && nums[r] == b) --r;
                }
            }
        }
        return ans;
    }
};
