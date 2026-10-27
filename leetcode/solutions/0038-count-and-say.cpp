// LeetCode 38: Count and Say
// Difficulty: Medium
// Approach: Build each term from the previous one by counting consecutive equal digits.
// Time: O(n * L), where L is the length of the generated term at each step (rough bound).
// Space: O(L) for the current and next terms.

#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string term = "1";

        for (int i = 2; i <= n; ++i) {
            string next;
            for (int j = 0; j < static_cast<int>(term.size());) {
                int k = j;
                while (k < static_cast<int>(term.size()) && term[k] == term[j]) {
                    ++k;
                }
                next += to_string(k - j);
                next += term[j];
                j = k;
            }
            term = next;
        }

        return term;
    }
};
