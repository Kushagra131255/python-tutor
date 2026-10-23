// LeetCode 23: Merge k Sorted Lists
// Difficulty: Hard
// Approach: Use a min-heap containing the current head of each non-empty list.
// Time: O(N log k); Space: O(k) heap
#include <queue>
#include <vector>
#include <functional>
using namespace std;
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        for (auto node : lists) if (node) heap.push(node);
        ListNode dummy(0); ListNode* tail = &dummy;
        while (!heap.empty()) {
            ListNode* node = heap.top(); heap.pop();
            tail->next = node; tail = node;
            if (node->next) heap.push(node->next);
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
