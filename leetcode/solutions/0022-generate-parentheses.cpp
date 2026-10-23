// LeetCode 22: Generate Parentheses
// Difficulty: Medium
// Approach: Backtrack, adding '(' while below n and ')' only when it won't exceed open count.
// Time: O(C_n * n), where C_n is the nth Catalan number; Space: O(n) recursion, excluding output
#include <string>
#include <vector>
using namespace std;
class Solution {
    void build(int n, int open, int close, string& path, vector<string>& out) {
        if (static_cast<int>(path.size()) == 2 * n) { out.push_back(path); return; }
        if (open < n) { path.push_back('('); build(n, open + 1, close, path, out); path.pop_back(); }
        if (close < open) { path.push_back(')'); build(n, open, close + 1, path, out); path.pop_back(); }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out; string path;
        build(n, 0, 0, path, out);
        return out;
    }
};
