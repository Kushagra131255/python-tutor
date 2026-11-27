#include <algorithm>
using std::max;

// Problem 104: Maximum Depth of Binary Tree
// Difficulty: Easy
// Approach: Recursively compute each subtree's maximum depth; add one for the current node.
// Time Complexity: O(n), where n is the number of nodes (each node is visited once).
// Space Complexity: O(h) for the recursion stack, where h is the tree height (O(n) worst case).
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
