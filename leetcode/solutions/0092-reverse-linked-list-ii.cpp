// LeetCode #92: Reverse Linked List II
// Difficulty: Medium
// Approach: Advance to the node before the requested range, then repeatedly
// move the next node to the front of that range to reverse links in place.
// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(1) auxiliary space.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* before = &dummy;
        for (int position = 1; position < left; ++position) {
            before = before->next;
        }

        ListNode* current = before->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* moving = current->next;
            current->next = moving->next;
            moving->next = before->next;
            before->next = moving;
        }

        return dummy.next;
    }
};
