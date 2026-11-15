// LeetCode 69. Sqrt(x)
// Difficulty: Easy
// Approach: Binary-search the largest integer r satisfying r <= x / r.
//           Handle r == 0 separately so division is always safe, and use
//           long long for the search bounds to avoid integer overflow.
// Time Complexity: O(log x), since the search interval is halved each iteration.
// Space Complexity: O(1), using only a fixed number of variables.

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        long long answer = 0;

        while (left <= right) {
            const long long mid = left + (right - left) / 2;

            if (mid == 0 || mid <= x / mid) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return static_cast<int>(answer);
    }
};
