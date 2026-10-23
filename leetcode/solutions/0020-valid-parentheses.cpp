// LeetCode 20: Valid Parentheses
// Difficulty: Easy
// Approach: Push opening brackets; each closing bracket must match the stack top.
// Time: O(n); Space: O(n)
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (st.empty()) return false;
                char open = st.top(); st.pop();
                if ((c == ')' && open != '(') ||
                    (c == ']' && open != '[') ||
                    (c == '}' && open != '{')) return false;
            }
        }
        return st.empty();
    }
};
