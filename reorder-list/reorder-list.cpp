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
    ListNode* reverse(ListNode* root) {
        if(root == nullptr
          || root->next == nullptr) {
            return root;
        }
        ListNode* prv = nullptr;
        auto cur = root;
        auto nxt = root->next;
        while(nxt != nullptr) {
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        return prv;
    }
public:
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head;
        auto prevSlow = head;
        while(fast != nullptr) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
            }
        }
        prevSlow->next = nullptr;
        
        bool revTurn = false;
        auto revHead = reverse(slow);
        while(head != nullptr && revHead != nullptr) {
            if(revTurn) {
                auto backup = revHead->next;
                revHead->next = head;
                revHead = backup;
            } else {
                auto backup = head->next;
                head->next = revHead;
                head = backup;
            }
            revTurn = !revTurn;
        }
    }
};