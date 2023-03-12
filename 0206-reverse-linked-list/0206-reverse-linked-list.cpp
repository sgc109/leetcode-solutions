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
    ListNode* reverse(ListNode* head) {
        if(head->next == nullptr) {
            return head;
        }
        auto ret = reverse(head->next);
        head->next->next = head;
        return ret;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        auto ret = reverse(head);
        head->next = nullptr;
        return ret;
    }
};