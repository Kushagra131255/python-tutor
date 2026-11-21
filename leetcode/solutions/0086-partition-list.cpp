// LeetCode 86: Partition List
// Difficulty: Medium
// Approach: Build two stable lists for nodes less than x and nodes at least x,
//           then connect the lists while preserving each partition's order.
// Time Complexity: O(n), where n is the number of nodes.
// Space Complexity: O(1) auxiliary space; nodes are relinked in place.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0);
        ListNode greaterDummy(0);
        ListNode* lessTail = &lessDummy;
        ListNode* greaterTail = &greaterDummy;

        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = nullptr;

            if (head->val < x) {
                lessTail->next = head;
                lessTail = head;
            } else {
                greaterTail->next = head;
                greaterTail = head;
            }

            head = nextNode;
        }

        lessTail->next = greaterDummy.next;
        return lessDummy.next;
    }
};
