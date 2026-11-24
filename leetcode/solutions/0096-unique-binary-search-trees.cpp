// LeetCode 96: Unique Binary Search Trees
// Difficulty: Medium
// Approach: Bottom-up dynamic programming. For each node count, try every
// possible root; multiply the counts for its left and right subtree sizes,
// then sum those combinations. dp[0] = 1 represents the empty subtree.
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int nodes = 1; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }

        return static_cast<int>(dp[n]);
    }
};
