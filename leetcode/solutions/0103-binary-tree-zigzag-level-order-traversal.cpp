#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
 * LeetCode 103: Binary Tree Zigzag Level Order Traversal
 * Difficulty: Medium
 * Approach: Breadth-first search. Collect each level in a pre-sized vector,
 * writing values at forward or mirrored indices according to the level's
 * direction. Enqueue children left-to-right so the next level stays ordered.
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(n) including the returned result; auxiliary space is
 * O(w), where w is the maximum width of the tree.
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        bool leftToRight = true;

        while (!nodes.empty()) {
            const int levelSize = static_cast<int>(nodes.size());
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = nodes.front();
                nodes.pop();

                const int index = leftToRight ? i : levelSize - 1 - i;
                level[index] = current->val;

                if (current->left != nullptr) {
                    nodes.push(current->left);
                }
                if (current->right != nullptr) {
                    nodes.push(current->right);
                }
            }

            result.push_back(std::move(level));
            leftToRight = !leftToRight;
        }

        return result;
    }
};
