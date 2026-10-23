// LeetCode 17: Letter Combinations of a Phone Number
// Difficulty: Medium
// Approach: Backtrack over the letters mapped to each digit.
// Time: O(4^n * n) upper bound; Space: O(n) recursion/path, excluding output
#include <string>
#include <vector>
using namespace std;
class Solution {
    const vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(const string& digits, int i, string& path, vector<string>& out) {
        if (i == static_cast<int>(digits.size())) { out.push_back(path); return; }
        for (char c : keys[digits[i] - '0']) {
            path.push_back(c);
            dfs(digits, i + 1, path, out);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;
        if (digits.empty()) return out;
        string path;
        dfs(digits, 0, path, out);
        return out;
    }
};
