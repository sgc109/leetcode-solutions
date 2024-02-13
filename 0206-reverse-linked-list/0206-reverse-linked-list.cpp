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
    ListNode* reverse(ListNode* cur, ListNode* prev) {
        if(cur == nullptr) {
            return prev;
        }
        auto ret = reverse(cur->next, cur);
        cur->next = prev;
        return ret;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
};