// LeetCode 4: Median of Two Sorted Arrays
// Difficulty: Hard
// Approach: Binary-search a partition in the shorter array so left halves contain half the values.
// Time: O(log(min(m,n))); Space: O(1)
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);
        int m = static_cast<int>(a.size()), n = static_cast<int>(b.size());
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = (m + n + 1) / 2 - i;
            int al = (i == 0) ? INT_MIN : a[i - 1];
            int ar = (i == m) ? INT_MAX : a[i];
            int bl = (j == 0) ? INT_MIN : b[j - 1];
            int br = (j == n) ? INT_MAX : b[j];
            if (al <= br && bl <= ar) {
                if ((m + n) % 2) return max(al, bl);
                return (static_cast<double>(max(al, bl)) + min(ar, br)) / 2.0;
            }
            if (al > br) hi = i - 1;
            else lo = i + 1;
        }
        return 0.0; // Inputs are expected to satisfy the problem constraints.
    }
};
