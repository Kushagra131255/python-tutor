#include <vector>
using namespace std;

/*
 * LeetCode #108 - Convert Sorted Array to Binary Search Tree
 * Difficulty: Easy
 * Approach: Recursively choose the middle element of each sorted interval
 * as its root. The left and right halves form the corresponding subtrees,
 * keeping their heights balanced.
 * Time Complexity: O(n), because each array element creates one tree node.
 * Space Complexity: O(log n) for the recursion stack of the balanced tree
 * (excluding the O(n) nodes in the returned tree).
 */
class Solution {
private:
    TreeNode* build(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        const int middle = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = build(nums, left, middle - 1);
        root->right = build(nums, middle + 1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};
