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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prv = dummy;
        ListNode* left = head;
        ListNode* right = left->next;
        while(right != nullptr) {
            if(left->val != right->val) {
                prv = left;
                left = right;
                right = right->next;
            }  else {
                while(right != nullptr && left->val == right->val) {
                    right = right->next;
                }
                prv->next = right;
                if(right == nullptr) break;
                left = right;
                right = right->next;
            }
        }
        return dummy->next;
    }
};