// LeetCode 1: Two Sum
// Difficulty: Easy
// Approach: Store each seen value's index; look for the complement before inserting.
// Time: O(n) average; Space: O(n)
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int need = target - nums[i];
            auto it = index.find(need);
            if (it != index.end()) return {it->second, i};
            index[nums[i]] = i;
        }
        return {};
    }
};
