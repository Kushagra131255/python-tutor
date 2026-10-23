// LeetCode 13: Roman to Integer
// Difficulty: Easy
// Approach: Subtract a symbol when its value is smaller than the next symbol; otherwise add it.
// Time: O(n); Space: O(1)
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> v = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int total = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (i + 1 < static_cast<int>(s.size()) && v[s[i]] < v[s[i + 1]]) total -= v[s[i]];
            else total += v[s[i]];
        }
        return total;
    }
};
