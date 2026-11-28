#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
 * LeetCode #107: Binary Tree Level Order Traversal II
 * Difficulty: Medium
 * Approach: Use breadth-first search to collect each level from left to right.
 * Process the queue's current size as one level, then reverse the collected
 * levels once to return them from the leaves up to the root.
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(n) including the result; the BFS queue uses O(w),
 * where w is the maximum width of the tree (O(n) in the worst case).
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            const int levelSize = static_cast<int>(nodes.size());
            vector<int> level;
            level.reserve(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = nodes.front();
                nodes.pop();
                level.push_back(current->val);

                if (current->left != nullptr) {
                    nodes.push(current->left);
                }
                if (current->right != nullptr) {
                    nodes.push(current->right);
                }
            }

            result.push_back(std::move(level));
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
