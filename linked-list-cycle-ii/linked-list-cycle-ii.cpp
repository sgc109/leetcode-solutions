/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *goNTimes(ListNode *start, int n) {
        for(int i = 0; i < n; i++) {
            if(start == nullptr) return nullptr;
            start = start->next;
        }
        return start;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(true) {
            slow = goNTimes(slow, 1);
            fast = goNTimes(fast, 2);
            if(fast == nullptr) return nullptr;
            if(slow == fast) break;
        }
        int cycleLen = 1;
        slow = slow->next;
        while(slow != fast) {
            slow = slow->next;
            cycleLen++;
        }
        ListNode *left = head;
        ListNode *right = head;
        for(int i = 0; i < cycleLen; i++) {
            right = right->next;
        }
        while(left != right) {
            left = left->next;
            right = right->next;
        }
        return left;
    }
};