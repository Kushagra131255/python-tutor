// LeetCode 29: Divide Two Integers
// Difficulty: Medium
// Approach: Use unsigned magnitudes and subtract shifted divisors from the dividend.
// Time: O(log^2 |dividend|) with the shift search below; Space: O(1)
#include <climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long a = dividend, b = divisor;
        bool negative = (a < 0) != (b < 0);
        unsigned long long x = a < 0 ? -a : a;
        unsigned long long y = b < 0 ? -b : b;
        unsigned long long quotient = 0;
        for (int shift = 31; shift >= 0; --shift) {
            if ((x >> shift) >= y) {
                x -= y << shift;
                quotient |= 1ULL << shift;
            }
        }
        long long result = negative ? -static_cast<long long>(quotient) : static_cast<long long>(quotient);
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return static_cast<int>(result);
    }
};
