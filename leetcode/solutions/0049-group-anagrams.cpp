// LeetCode 49: Group Anagrams
// Difficulty: Medium
// Approach: Use each word's sorted characters as a key; words with the same key are anagrams.
// Time: O(N * K log K) — sorting each of N strings of maximum length K.
// Space: O(N * K) — stores the grouped strings and their keys.

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        result.reserve(groups.size());

        for (auto& entry : groups) {
            result.push_back(move(entry.second));
        }

        return result;
    }
};
