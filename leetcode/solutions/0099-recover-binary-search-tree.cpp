#include <utility>

/*
 * LeetCode #99 - Recover Binary Search Tree
 * Difficulty: Medium
 *
 * Approach:
 * Morris inorder traversal visits nodes in sorted order without recursion
 * or an explicit stack. Record the first and last nodes involved in inorder
 * inversions, then swap their values. Temporary threaded links are restored
 * during traversal, so the tree structure is unchanged.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1) auxiliary space.
 */

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* previous = nullptr;
        TreeNode* current = root;

        auto visit = [&](TreeNode* node) {
            if (previous != nullptr && previous->val > node->val) {
                if (first == nullptr) {
                    first = previous;
                }
                second = node;
            }
            previous = node;
        };

        while (current != nullptr) {
            if (current->left == nullptr) {
                visit(current);
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr &&
                       predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    visit(current);
                    current = current->right;
                }
            }
        }

        if (first != nullptr && second != nullptr) {
            std::swap(first->val, second->val);
        }
    }
};
