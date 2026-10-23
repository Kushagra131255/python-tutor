// LeetCode 19: Remove Nth Node From End of List
// Difficulty: Medium
// Approach: Advance a lead pointer n steps, then move lead and trail together.
// Time: O(n); Space: O(1)
// LeetCode provides the ListNode definition.
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* lead = &dummy;
        ListNode* trail = &dummy;
        for (int i = 0; i < n; ++i) lead = lead->next;
        while (lead->next) { lead = lead->next; trail = trail->next; }
        ListNode* removed = trail->next;
        trail->next = removed->next;
        delete removed;
        return dummy.next;
    }
};
