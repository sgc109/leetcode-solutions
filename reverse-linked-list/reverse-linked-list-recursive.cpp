/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* cur, ListNode* nxt) {
        if(nxt == nullptr) return cur;
        ListNode* backup = nxt->next;
        nxt->next = cur;
        return reverse(nxt, backup);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* newHead = reverse(head, head->next);
        head->next = nullptr;
        return newHead;
    }
};
