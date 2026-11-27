#include <unordered_map>
#include <vector>
using namespace std;

// LeetCode #106: Construct Binary Tree from Inorder and Postorder Traversal
// Difficulty: Medium
// Approach: Map each value to its inorder index. Consume postorder from right
// to left; build the right subtree before the left subtree.
// Time Complexity: O(n) average, where n is the number of nodes.
// Space Complexity: O(n) for the index map and recursion stack in the worst case.
class Solution {
private:
    unordered_map<int, int> inorderIndex;
    int postorderIndex = 0;

    TreeNode* build(const vector<int>& postorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        const int value = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(value);
        const int middle = inorderIndex.at(value);

        root->right = build(postorder, middle + 1, right);
        root->left = build(postorder, left, middle - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorderIndex.clear();
        inorderIndex.reserve(inorder.size());
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        postorderIndex = static_cast<int>(postorder.size()) - 1;
        return build(postorder, 0, static_cast<int>(inorder.size()) - 1);
    }
};
