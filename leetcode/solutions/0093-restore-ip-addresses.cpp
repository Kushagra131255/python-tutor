// LeetCode 93: Restore IP Addresses
// Difficulty: Medium
// Approach: Backtracking. Build exactly four segments, trying lengths 1..3;
// reject leading zeros and values above 255, and prune impossible remaining lengths.
// Time: O(3^4) (at most three choices for each of four IPv4 segments).
// Space: O(1) auxiliary space (recursion depth and path are bounded by four segments), excluding output.

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(const string& s, int index, int segments,
                   string& path, vector<string>& result) {
        if (segments == 4) {
            if (index == static_cast<int>(s.size())) {
                result.push_back(path);
            }
            return;
        }

        const int remainingSegments = 4 - segments;
        const int remainingChars = static_cast<int>(s.size()) - index;
        if (remainingChars < remainingSegments ||
            remainingChars > 3 * remainingSegments) {
            return;
        }

        int value = 0;
        for (int length = 1; length <= 3 && index + length <= static_cast<int>(s.size()); ++length) {
            if (length > 1 && s[index] == '0') {
                break;
            }

            value = value * 10 + (s[index + length - 1] - '0');
            if (value > 255) {
                break;
            }

            const size_t previousSize = path.size();
            if (segments > 0) {
                path.push_back('.');
            }
            path.append(s, index, length);

            backtrack(s, index + length, segments + 1, path, result);
            path.resize(previousSize);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() < 4 || s.size() > 12) {
            return result;
        }

        string path;
        backtrack(s, 0, 0, path, result);
        return result;
    }
};
