// LeetCode #94: Binary Tree Inorder Traversal
// Difficulty: Easy
// Approach: Iterative inorder traversal. Push the left path onto a stack,
// visit the top node, then continue through its right subtree.
// Time Complexity: O(n), where n is the number of nodes.
// Space Complexity: O(h) auxiliary space for the stack, where h is tree height
// (O(n) in the worst case), excluding the output vector.

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        TreeNode* current = root;

        while (current != nullptr || !nodes.empty()) {
            while (current != nullptr) {
                nodes.push(current);
                current = current->left;
            }

            current = nodes.top();
            nodes.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }
};
