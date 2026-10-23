// LeetCode 18: 4Sum
// Difficulty: Medium
// Approach: Sort, fix two values, then search with two pointers and skip duplicates.
// Time: O(n^3); Space: O(1) auxiliary excluding sorting and output
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) ++l;
                    else if (sum > target) --r;
                    else {
                        out.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int a = nums[l], b = nums[r];
                        while (l < r && nums[l] == a) ++l;
                        while (l < r && nums[r] == b) --r;
                    }
                }
            }
        }
        return out;
    }
};
