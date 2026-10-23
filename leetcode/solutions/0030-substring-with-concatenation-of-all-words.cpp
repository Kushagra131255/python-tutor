// LeetCode 30: Substring with Concatenation of All Words
// Difficulty: Hard
// Approach: For each word-length offset, slide a fixed-width window and track word frequencies.
// Time: O(n * wordLength) average with hash maps; Space: O(total distinct words)
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || words[0].empty()) return ans;
        int w = static_cast<int>(words[0].size());
        int needCount = static_cast<int>(words.size());
        int total = w * needCount;
        if (static_cast<int>(s.size()) < total) return ans;
        unordered_map<string, int> need;
        for (const auto& word : words) ++need[word];
        for (int offset = 0; offset < w; ++offset) {
            unordered_map<string, int> have;
            int left = offset, used = 0;
            for (int right = offset; right + w <= static_cast<int>(s.size()); right += w) {
                string word = s.substr(right, w);
                if (!need.count(word)) { have.clear(); used = 0; left = right + w; continue; }
                ++have[word]; ++used;
                while (have[word] > need[word]) {
                    string first = s.substr(left, w);
                    --have[first]; --used; left += w;
                }
                if (used == needCount) {
                    ans.push_back(left);
                    string first = s.substr(left, w);
                    --have[first]; --used; left += w;
                }
            }
        }
        return ans;
    }
};
