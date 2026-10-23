// LeetCode 9: Palindrome Number
// Difficulty: Easy
// Approach: Reverse only half the digits and compare the two halves.
// Time: O(log10(n)); Space: O(1)
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
