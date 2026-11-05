// LeetCode 56: Merge Intervals
// Difficulty: Medium
// Approach: Sort intervals by start time. Add the first interval, then merge
// each overlapping interval into the last result; otherwise, add a new one.
// Time: O(N log N) — sorting dominates; merging takes O(N).
// Space: O(N) — the output stores up to N intervals (excluding sort internals).

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
