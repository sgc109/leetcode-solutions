class Solution {
    class Node {
    public:
        int num;
        Node* next;
        Node(int _num) : num(_num), next(nullptr) {}
    };
    
    Node* vector2list(vector<int>& v) {
        Node* root = new Node(0);
        Node* last = root;
        for(int num : v) {
            last->next = new Node(num);
            last = last->next;
        }
        return root;
    }
    
    bool compareLists(Node* list1, Node* list2) {
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->num != list2->num) return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
    
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        Node* last = nullptr;
        for(auto& row : matrix) {
            Node* cur = vector2list(row);
            if(last != nullptr) {
                if(!compareLists(last->next, cur->next->next)) return false;
            }
            last = cur;
        }
        return true;
    }
};
