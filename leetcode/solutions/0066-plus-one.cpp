// LeetCode 66. Plus One
// Difficulty: Easy
// Approach: Simulate addition from right to left. Turn trailing 9s into 0s
//           until a digit can be incremented; if every digit was 9, add a
//           leading 1.
// Time Complexity: O(n), where n is the number of digits.
// Space Complexity: O(1) auxiliary space, excluding the returned vector.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
