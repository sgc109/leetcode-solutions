class LRUCache {
    struct ListNode {
        int key;
        int val;
        ListNode* left;
        ListNode* right;
        ListNode(int key, int val): key(key), val(val), left(nullptr), right(nullptr) {}
    };
    unordered_map<int, ListNode*> keyToNode;
    ListNode* head;
    ListNode* tail;
    int capacity;

    void remove(ListNode* target) {
        target->left->right = target->right;
        target->right->left = target->left;
    }

    void append(ListNode* target) {
        tail->left->right = target;
        target->left = tail->left;
        target->right = tail;
        tail->left = target;
    }

    void refresh(ListNode* target) {
        remove(target);
        append(target);
    }
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(!keyToNode.count(key)) {
            return -1;
        }
        auto node = keyToNode[key];
        refresh(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!keyToNode.count(key)) {
            if(keyToNode.size() == capacity) {
                keyToNode.erase(head->right->key);
                remove(head->right);
            }
            ListNode* newNode = new ListNode(key, value);
            keyToNode[key] = newNode;
            append(newNode);
            return;
        }
        ListNode* node = keyToNode[key];
        node->val = value;
        refresh(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */