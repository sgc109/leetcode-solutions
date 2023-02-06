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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(-1, head);
        
        ListNode* cur = dummy;
        for(int i = 0; i < left - 1; ++i) {
            cur = cur->next;
        }
        ListNode* left1 = cur;
        ListNode* left2 = cur->next;
        
        ListNode* one = left1->next;
        ListNode* two = left2->next;
        for(int i = 0; i < right - left; ++i) {
            ListNode* oneNext = two;
            ListNode* twoNext = two->next;
            
            two->next = one;
            
            one = oneNext;
            two = twoNext;
        }
        left1->next = one;
        left2->next = two;
        
        return dummy->next;
    }
};