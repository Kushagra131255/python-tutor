// LeetCode 61: Rotate List
// Difficulty: Medium
// Approach: Find the list length and connect the tail to the head to form a
// circle. Move to the new tail at length - (k % length) - 1, then break the circle.
// Time: O(N) — the list is traversed a constant number of times.
// Space: O(1) — only pointers and counters are used.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int length = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            ++length;
        }

        int rotations = k % length;
        if (rotations == 0) {
            return head;
        }

        // Temporarily make the list circular.
        tail->next = head;

        int stepsToNewTail = length - rotations - 1;
        ListNode* newTail = head;

        for (int i = 0; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
