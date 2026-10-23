// LeetCode 24: Swap Nodes in Pairs
// Difficulty: Medium
// Approach: Rewire each adjacent pair using a dummy node and advance to the next pair.
// Time: O(n); Space: O(1)
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0); dummy.next = head;
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        return dummy.next;
    }
};
