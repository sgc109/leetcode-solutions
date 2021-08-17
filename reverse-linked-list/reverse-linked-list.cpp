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
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while(nxt != nullptr) {
            ListNode* backup = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = backup;
        }
        head->next = nullptr;
        return cur;
    }
};