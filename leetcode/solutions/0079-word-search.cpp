// Problem 79: Word Search
// Difficulty: Medium
// Approach: Use DFS/backtracking from each cell matching the first character.
//           Mark visited cells in-place, explore four directions, then restore
//           the cell. Reverse the word when its last character is rarer to
//           reduce the number of starting points.
// Time Complexity: O(m * n * 3^L) — each start has at most four first moves,
//                  then at most three choices per level (L = word length).
// Space Complexity: O(L) auxiliary — recursion depth; the board is reused.

#include <algorithm>
#include <array>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    int rows = 0;
    int cols = 0;
    string target;

    bool dfs(vector<vector<char>>& board, int r, int c, int index) {
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            board[r][c] != target[index]) {
            return false;
        }

        if (index == static_cast<int>(target.size()) - 1) {
            return true;
        }

        char original = board[r][c];
        board[r][c] = '#'; // Temporarily mark this cell as visited.

        bool found = dfs(board, r + 1, c, index + 1) ||
                     dfs(board, r - 1, c, index + 1) ||
                     dfs(board, r, c + 1, index + 1) ||
                     dfs(board, r, c - 1, index + 1);

        board[r][c] = original; // Restore for other search paths.
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;

        rows = static_cast<int>(board.size());
        cols = static_cast<int>(board[0].size());
        if (static_cast<int>(word.size()) > rows * cols) return false;

        array<int, 256> boardCount{};
        array<int, 256> wordCount{};
        for (const auto& row : board) {
            for (char ch : row) {
                ++boardCount[static_cast<unsigned char>(ch)];
            }
        }
        for (char ch : word) {
            ++wordCount[static_cast<unsigned char>(ch)];
        }
        for (int ch = 0; ch < 256; ++ch) {
            if (wordCount[ch] > boardCount[ch]) return false;
        }

        // A path can be traversed in either direction, so start with the rarer end.
        if (boardCount[static_cast<unsigned char>(word.front())] >
            boardCount[static_cast<unsigned char>(word.back())]) {
            reverse(word.begin(), word.end());
        }
        target = std::move(word);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == target[0] && dfs(board, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
