/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return head;
        }
        unordered_map<Node*, Node*> originalToNew;
        Node* newHead = new Node(head->val);
        originalToNew[head] = newHead;
        Node* cur = head;
        while(cur) {
            Node* newCur = originalToNew[cur];
            if(cur->next) {
                if(!originalToNew.count(cur->next)) {
                    originalToNew[cur->next] = new Node(cur->next->val);
                }
                newCur->next = originalToNew[cur->next];
            }
            if(cur->random) {
                if(!originalToNew.count(cur->random)) {
                    originalToNew[cur->random] = new Node(cur->random->val);
                }
                newCur->random = originalToNew[cur->random];
            }
            cur = cur->next;
        }

        return newHead;
    }
};