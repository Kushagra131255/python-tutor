// LeetCode 21: Merge Two Sorted Lists
// Difficulty: Easy
// Approach: Repeatedly attach the smaller current node to a dummy-headed result list.
// Time: O(m+n); Space: O(1) auxiliary
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) { tail->next = list1; list1 = list1->next; }
            else { tail->next = list2; list2 = list2->next; }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
