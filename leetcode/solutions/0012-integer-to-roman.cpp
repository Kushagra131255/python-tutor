// LeetCode 12: Integer to Roman
// Difficulty: Medium
// Approach: Greedily consume values from largest to smallest, including subtractive pairs.
// Time: O(1) for the bounded input range; Space: O(1) auxiliary
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> values = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},
            {50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string out;
        for (const auto& [value, symbol] : values) {
            while (num >= value) { out += symbol; num -= value; }
        }
        return out;
    }
};
