/*
 * LeetCode #101 - Symmetric Tree
 * Difficulty: Easy
 *
 * Approach:
 * Compare the left and right subtrees as mirrored node pairs. Two null
 * nodes match; one null node or unequal values fail. Recursively compare
 * the outer children and then the inner children.
 *
 * Time Complexity: O(n), since each node is visited at most once.
 * Space Complexity: O(h) for the recursion stack, where h is tree height;
 * O(n) in the worst case for a skewed tree.
 */

class Solution {
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }

        return left->val == right->val &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isMirror(root->left, root->right);
    }
};
