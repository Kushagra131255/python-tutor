/*
 * LeetCode #100 - Same Tree
 * Difficulty: Easy
 *
 * Approach:
 * Recursively compare nodes at corresponding positions in both trees.
 * Two null nodes match; one null node or unequal values indicate a mismatch.
 * Otherwise, both the left and right child pairs must match.
 *
 * Time Complexity: O(min(m, n)), where m and n are the node counts.
 * Space Complexity: O(h), for the recursion stack, where h is the
 * smaller of the two tree heights; O(min(m, n)) in the worst case.
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
