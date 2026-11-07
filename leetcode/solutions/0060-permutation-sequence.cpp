// LeetCode 60: Permutation Sequence
// Difficulty: Hard
// Approach: Use the factorial number system to choose each digit directly.
// Convert k to zero-based indexing, select the digit at k / (n - 1)!,
// then update k with the remainder and remove the selected digit.
// Time: O(N^2) — selecting and erasing from the available digits takes O(N).
// Space: O(N) — factorial values, available digits, and the result use O(N).

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        vector<int> digits;
        for (int i = 1; i <= n; ++i) {
            digits.push_back(i);
        }

        --k; // Convert to zero-based indexing.
        string result;

        for (int remaining = n; remaining > 0; --remaining) {
            int blockSize = factorial[remaining - 1];
            int index = k / blockSize;

            result += to_string(digits[index]);
            digits.erase(digits.begin() + index);

            k %= blockSize;
        }

        return result;
    }
};
