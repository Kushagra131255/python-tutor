// LeetCode 32: Longest Valid Parentheses
// Difficulty: Hard
// Approach: Keep indices on a stack. Start with -1 as the base index.
// Push opening-parenthesis indices; for a closing parenthesis, pop once.
// If the stack becomes empty, set the current index as the new base;
// otherwise, the current valid length is i - stack.top().
// Time: O(n) | Space: O(n)

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> indices;
        indices.push_back(-1);
        int best = 0;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == '(') {
                indices.push_back(i);
            } else {
                indices.pop_back();

                if (indices.empty()) {
                    indices.push_back(i);
                } else {
                    best = max(best, i - indices.back());
                }
            }
        }

        return best;
    }
};
