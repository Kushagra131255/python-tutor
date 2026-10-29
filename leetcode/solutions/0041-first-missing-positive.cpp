// LeetCode 41: First Missing Positive
// Difficulty: Hard
// Approach: Place each value x in index x - 1 when x is in [1, n].
// Then the first index whose value is not index + 1 gives the answer.
// Time: O(N) — each value is moved into its correct position at most once.
// Space: O(1) extra space — modifies the input array in place.

#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};
