#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * LeetCode #105 - Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Approach: Map each inorder value to its index. A preorder cursor selects
 * each subtree root; its inorder position splits the remaining range into
 * left and right subtrees. Build left before right to preserve preorder.
 * Time Complexity: O(n), since each node is created once and each lookup is O(1) average.
 * Space Complexity: O(n) for the index map and recursion stack (worst case).
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        inorderIndex.reserve(inorder.size());
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        int preorderIndex = 0;
        function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }

            const int rootValue = preorder[preorderIndex++];
            TreeNode* root = new TreeNode(rootValue);
            const int middle = inorderIndex.at(rootValue);

            root->left = build(left, middle - 1);
            root->right = build(middle + 1, right);
            return root;
        };

        return build(0, static_cast<int>(inorder.size()) - 1);
    }
};
