// LeetCode #89: Gray Code
// Difficulty: Medium
// Approach: Generate the reflected binary Gray code directly: the code at index i is i XOR (i >> 1).
// Time Complexity: O(2^n), one constant-time calculation per output value.
// Space Complexity: O(2^n) for the returned sequence; O(1) auxiliary space.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        const int count = 1 << n;
        vector<int> result;
        result.reserve(count);

        for (int i = 0; i < count; ++i) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }
};
