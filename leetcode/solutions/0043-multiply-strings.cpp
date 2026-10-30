// LeetCode 43: Multiply Strings
// Difficulty: Medium
// Approach: Multiply digit-by-digit using an array to store place-value sums.
// This avoids converting the input strings into built-in numeric types.
// Time: O(M * N), where M and N are the lengths of the input strings.
// Space: O(M + N) for the result array.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = static_cast<int>(num1.size());
        int n = static_cast<int>(num2.size());
        vector<int> digits(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + digits[i + j + 1];

                digits[i + j + 1] = sum % 10;
                digits[i + j] += sum / 10;
            }
        }

        string result;
        int i = 0;
        while (i < static_cast<int>(digits.size()) && digits[i] == 0) {
            ++i;
        }

        for (; i < static_cast<int>(digits.size()); ++i) {
            result.push_back(static_cast<char>('0' + digits[i]));
        }

        return result.empty() ? "0" : result;
    }
};
