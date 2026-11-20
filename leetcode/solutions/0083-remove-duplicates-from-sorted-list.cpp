#include <cstddef>

// LeetCode #83: Remove Duplicates from Sorted List
// Difficulty: Easy
// Approach: Walk the sorted list once. If the next node has the same value,
// bypass it; otherwise advance. The first node of each value is retained,
// so the head never changes and no auxiliary data structure is needed.
// Time: O(n) — each link is examined a constant number of times.
// Space: O(1) — only one traversal pointer is used.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
