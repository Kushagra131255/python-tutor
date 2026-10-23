// LeetCode 2: Add Two Numbers
// Difficulty: Medium
// Approach: Add corresponding digits with a carry and build the result list.
// Time: O(max(m,n)); Space: O(max(m,n)) for the output
#include <cstddef>
using namespace std;

// LeetCode provides this definition:
// struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ... };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        return dummy.next;
    }
};
