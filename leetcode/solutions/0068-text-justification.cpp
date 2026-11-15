// LeetCode 68. Text Justification
// Difficulty: Hard
// Approach: Greedily pack the maximum number of words into each line. For
//           non-final multi-word lines, divide spaces evenly across gaps and
//           give leftover spaces to the leftmost gaps. Left-justify the final
//           line and any line containing only one word.
// Time Complexity: O(L), where L is the total number of characters in the output.
// Space Complexity: O(L) for the returned lines; O(maxWidth) auxiliary space.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        const int n = static_cast<int>(words.size());
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Include the mandatory one-space separator before each new word.
            while (j < n && letters + static_cast<int>(words[j].size()) + (j - i) <= maxWidth) {
                letters += static_cast<int>(words[j].size());
                ++j;
            }

            const int wordCount = j - i;
            string line;

            if (j == n || wordCount == 1) {
                // The final line and single-word lines are left-justified.
                for (int k = i; k < j; ++k) {
                    if (k > i) line.push_back(' ');
                    line += words[k];
                }
                line.append(maxWidth - static_cast<int>(line.size()), ' ');
            } else {
                const int gaps = wordCount - 1;
                const int totalSpaces = maxWidth - letters;
                const int spacesPerGap = totalSpaces / gaps;
                const int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        const int gapWidth = spacesPerGap + ((k - i) < extraSpaces ? 1 : 0);
                        line.append(gapWidth, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
