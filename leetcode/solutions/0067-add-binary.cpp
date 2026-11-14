// LeetCode 67. Add Binary
// Difficulty: Easy
// Approach: Add the two binary strings from right to left, keeping a carry.
//           Append each result bit and reverse the completed string.
// Time Complexity: O(max(m, n)), where m and n are the input lengths.
// Space Complexity: O(max(m, n)) for the returned result string.

#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result.push_back(static_cast<char>('0' + (sum % 2)));
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
