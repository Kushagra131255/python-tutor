#include <climits>

/*
 * LeetCode #98 - Validate Binary Search Tree
 * Difficulty: Medium
 *
 * Approach:
 * DFS with exclusive lower and upper bounds. Each node must stay within
 * the range imposed by all its ancestors; tighten one bound when descending.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(h) for the recursion stack, where h is the tree height
 * (O(n) in the worst case).
 */

class Solution {
private:
    bool validate(TreeNode* node, long long lower, long long upper) {
        if (node == nullptr) {
            return true;
        }

        const long long value = node->val;
        if (value <= lower || value >= upper) {
            return false;
        }

        return validate(node->left, lower, value) &&
               validate(node->right, value, upper);
    }

public:
    bool isValidBST(TreeNode* root) {
        // 64-bit bounds safely include every possible 32-bit node value.
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
