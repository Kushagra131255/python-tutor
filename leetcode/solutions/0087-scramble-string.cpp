#include <array>
#include <functional>
#include <string>
#include <vector>

using namespace std;

// LeetCode #87: Scramble String
// Difficulty: Hard
// Approach: Memoized interval recursion. State (i, j, len) asks whether the
//           length-len substring at s1[i] can scramble into the substring at
//           s2[j]. Try every split with both swapped and unswapped cases;
//           prefix character counts prune states with different multisets.
// Time: O(n^4) — O(n^3) states, up to O(n) splits per state (26-count
//       comparisons add only a constant factor).
// Space: O(n^3) for memoization, plus O(n) prefix-count storage and recursion.
class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int n = static_cast<int>(s1.size());
        if (n != static_cast<int>(s2.size())) {
            return false;
        }

        vector<array<int, 26>> prefix1(n + 1), prefix2(n + 1);
        prefix1[0].fill(0);
        prefix2[0].fill(0);
        for (int i = 0; i < n; ++i) {
            prefix1[i + 1] = prefix1[i];
            prefix2[i + 1] = prefix2[i];
            ++prefix1[i + 1][s1[i] - 'a'];
            ++prefix2[i + 1][s2[i] - 'a'];
        }

        // -1 = unknown, 0 = false, 1 = true.
        vector<vector<vector<signed char>>> memo(
            n, vector<vector<signed char>>(n, vector<signed char>(n + 1, -1)));

        auto sameMultiset = [&](int i, int j, int len) {
            for (int c = 0; c < 26; ++c) {
                const int count1 = prefix1[i + len][c] - prefix1[i][c];
                const int count2 = prefix2[j + len][c] - prefix2[j][c];
                if (count1 != count2) {
                    return false;
                }
            }
            return true;
        };

        function<bool(int, int, int)> dfs = [&](int i, int j, int len) -> bool {
            signed char& cached = memo[i][j][len];
            if (cached != -1) {
                return cached == 1;
            }

            if (s1.compare(i, len, s2, j, len) == 0) {
                cached = 1;
                return true;
            }
            if (!sameMultiset(i, j, len)) {
                cached = 0;
                return false;
            }

            for (int split = 1; split < len; ++split) {
                const bool withoutSwap =
                    dfs(i, j, split) && dfs(i + split, j + split, len - split);
                const bool withSwap =
                    dfs(i, j + len - split, split) && dfs(i + split, j, len - split);
                if (withoutSwap || withSwap) {
                    cached = 1;
                    return true;
                }
            }

            cached = 0;
            return false;
        };

        return dfs(0, 0, n);
    }
};
