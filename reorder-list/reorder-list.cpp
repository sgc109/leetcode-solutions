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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while(cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        int l = 0, r = nodes.size() - 1;
        bool leftFirst = true;
        while(l < r) {
            if(leftFirst) {
                nodes[l]->next = nodes[r];
                ++l;
            } else {
                nodes[r]->next = nodes[l];
                --r;
            }
            leftFirst = !leftFirst;
        }
        nodes[l]->next = nullptr;
    }
};