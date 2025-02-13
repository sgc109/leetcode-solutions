/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if(!head) {
            newNode->next = newNode;
            return newNode;
        }
        Node* cur = head;
        Node* next = cur->next;
        while(next != head) {
            if((cur->val > next->val && (cur->val <= insertVal || insertVal <= next->val)) || 
            (cur->val <= insertVal && insertVal <= next->val)) {
                cur->next = newNode;
                newNode->next = next;
                return head;
            }
            
            cur = next;
            next = next->next;
        }

        cur->next = newNode;
        newNode->next = head;

        return head;
    }
};
