#include <map>
#include <utility>
#include <vector>
using namespace std;

/*
 * LeetCode 95: Unique Binary Search Trees II
 * Difficulty: Medium
 * Approach: Choose each value in an interval as the root, recursively build
 * all left and right subtree combinations, and memoize each interval. Clone
 * both selected subtrees so every returned tree owns independent nodes.
 * Time: O(n * C_n), where C_n is the nth Catalan number.
 * Space: O(n * C_n) for generated/memoized trees, plus O(n) recursion depth.
 */
class Solution {
private:
    map<pair<int, int>, vector<TreeNode*>> memo;

    TreeNode* cloneTree(TreeNode* node) {
        if (node == nullptr) return nullptr;

        TreeNode* copy = new TreeNode(node->val);
        copy->left = cloneTree(node->left);
        copy->right = cloneTree(node->right);
        return copy;
    }

    vector<TreeNode*> build(int first, int last) {
        if (first > last) return {nullptr};

        const pair<int, int> range = {first, last};
        auto cached = memo.find(range);
        if (cached != memo.end()) return cached->second;

        vector<TreeNode*> trees;

        for (int rootValue = first; rootValue <= last; ++rootValue) {
            const vector<TreeNode*> leftTrees = build(first, rootValue - 1);
            const vector<TreeNode*> rightTrees = build(rootValue + 1, last);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootValue);
                    root->left = cloneTree(left);
                    root->right = cloneTree(right);
                    trees.push_back(root);
                }
            }
        }

        memo.emplace(range, trees);
        return trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        memo.clear();
        if (n == 0) return {};
        return build(1, n);
    }
};
