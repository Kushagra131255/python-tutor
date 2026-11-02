// LeetCode 50: Pow(x, n)
// Difficulty: Medium
// Approach: Binary exponentiation (exponentiation by squaring). Convert negative exponents
// to positive using a long long so INT_MIN is handled safely, then take the reciprocal.
// Time: O(log |n|) — the exponent is halved on each iteration.
// Space: O(1) extra space — iterative implementation.

class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;
        if (exponent < 0) {
            x = 1.0 / x;
            exponent = -exponent;
        }

        double result = 1.0;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result *= x;
            }

            x *= x;
            exponent /= 2;
        }

        return result;
    }
};
