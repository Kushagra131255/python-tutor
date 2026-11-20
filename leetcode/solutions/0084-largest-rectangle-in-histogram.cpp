#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// LeetCode #84: Largest Rectangle in Histogram
// Difficulty: Hard
// Approach: Maintain an increasing stack of bar indices. When a shorter
// bar arrives, each popped bar has found its first smaller bar on the right;
// the new stack top gives its first smaller bar on the left. A zero-height
// sentinel flushes the remaining bars after the scan.
// Time: O(n) — each index is pushed and popped at most once.
// Space: O(n) — the monotonic stack can hold all bar indices.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = static_cast<int>(heights.size());
        stack<int> indices;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            const int currentHeight = (i == n) ? 0 : heights[i];

            while (!indices.empty() &&
                   heights[indices.top()] >= currentHeight) {
                const int height = heights[indices.top()];
                indices.pop();

                const int width = indices.empty()
                                      ? i
                                      : i - indices.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            if (i < n) {
                indices.push(i);
            }
        }

        return maxArea;
    }
};
