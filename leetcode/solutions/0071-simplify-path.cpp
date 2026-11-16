#include <bits/stdc++.h>
using namespace std;

// LeetCode #71: Simplify Path
// Difficulty: Medium
// Approach: Split the absolute path into components. Ignore empty components
// and ".", pop one directory for ".." when possible, and keep normal names.
// Join the remaining components with single slashes to form the canonical path.
// Time Complexity: O(n), where n is the length of the input path.
// Space Complexity: O(n) for the stored path components and output.
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories;
        string component;
        stringstream stream(path);

        while (getline(stream, component, '/')) {
            if (component.empty() || component == ".") {
                continue;
            }

            if (component == "..") {
                if (!directories.empty()) {
                    directories.pop_back();
                }
            } else {
                directories.push_back(component);
            }
        }

        string canonicalPath;
        for (const string& directory : directories) {
            canonicalPath += "/" + directory;
        }

        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};
