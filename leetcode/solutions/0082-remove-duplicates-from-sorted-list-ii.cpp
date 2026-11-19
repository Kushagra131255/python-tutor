#include <vector>
using namespace std;

// LeetCode #82: Remove Duplicates from Sorted List II
// Difficulty: Medium
// Approach: Use a dummy head and a pointer to the last retained node. When
// the current value begins a duplicate run, skip the entire run; otherwise,
// link the current node into the result and advance both pointers.
// Time: O(n) — every node is visited at most once.
// Space: O(1) — only a dummy node and a constant number of pointers are used.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* lastUnique = &dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                const int duplicateValue = head->val;
                while (head != nullptr && head->val == duplicateValue) {
                    head = head->next;
                }
                lastUnique->next = head;
            } else {
                lastUnique = head;
                head = head->next;
            }
        }

        return dummy.next;
    }
};
