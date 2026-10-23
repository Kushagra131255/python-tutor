// LeetCode 25: Reverse Nodes in k-Group
// Difficulty: Hard
// Approach: Check that a full group exists, reverse its links, then continue after the group.
// Time: O(n); Space: O(1)
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0); dummy.next = head;
        ListNode* groupPrev = &dummy;
        while (true) {
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; ++i) kth = kth->next;
            if (!kth) break;
            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* cur = groupPrev->next;
            while (cur != groupNext) {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            ListNode* oldHead = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldHead;
        }
        return dummy.next;
    }
};
