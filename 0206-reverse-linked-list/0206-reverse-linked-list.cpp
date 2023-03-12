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
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* one = nullptr;
        auto two = head;
        auto three = two->next;
        while(two) {
            two->next = one;
            one = two;
            two = three;
            if(three != nullptr) {
                three = three->next;
            }
        }
        return one;
    }
};