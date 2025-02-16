class LRUCache {
    struct ListNode {
        int key;
        int value;
        ListNode* left;
        ListNode* right;

        ListNode(int key, int value) {
            this->key = key;
            this->value = value;
            left = right = nullptr;
        }
    };
    int capacity;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> keyToNode;

    void append(ListNode* target) {
        if(!head) {
            head = tail = target;
        } else {
            tail->right = target;
            target->left = tail;
            target->right = nullptr;
            tail = target;
        }
    }

    // 'target' must exist in List already
    void remove(ListNode* target) {
        ListNode* left = target->left;
        ListNode* right = target->right;
        if(left) {
            left->right = right;
        }
        if(right) {
            right->left = left;
        }
        if(head == target) {
            head = right;
        }
        if(tail == target) {
            tail = left;
        }
    }

    // 'target' must exist in List already
    void refresh(ListNode* target) {
        if(!head) {
            head = tail = target;
        } else {
            remove(target);
            append(target);
        }
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = this->tail = nullptr;
    }
    
    int get(int key) {
        if(!keyToNode.count(key)) {
            return -1;
        }
        ListNode* target = keyToNode[key];
        refresh(target);
        return target->value;
    }
    
    void put(int key, int value) {
        if(!keyToNode.count(key)) {
            if(keyToNode.size() == capacity) {
                keyToNode.erase(head->key);
                ListNode* backup = head;
                remove(head);
                delete backup;
            }
            ListNode* newNode = new ListNode(key, value);
            keyToNode[key] = newNode;
            append(newNode);
            return;
        }
        ListNode* target = keyToNode[key];
        target->value = value;
        refresh(target);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */