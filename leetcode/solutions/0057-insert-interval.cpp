// LeetCode 57: Insert Interval
// Difficulty: Medium
// Approach: Add intervals that end before the new interval, merge all
// overlapping intervals into it, then append the remaining intervals.
// Time: O(N) — each existing interval is processed once.
// Space: O(N) — the result may contain up to N + 1 intervals.

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = static_cast<int>(intervals.size());

        // Add intervals that do not overlap and come before newInterval.
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }

        // Merge every interval that overlaps newInterval.
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);

        // Add all intervals that come after the merged interval.
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};
