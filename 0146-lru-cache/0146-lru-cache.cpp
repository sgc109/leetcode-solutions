class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> keyToNode;
    int capacity; // 2
    Node* head;
    Node* tail;

    void remove(Node* target) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    
    void append(Node* target) {
        tail->prev->next = target;
        target->prev = tail->prev;
        target->next = tail;
        tail->prev = target;
    }

    void refresh(Node* target) {
        remove(target);
        append(target);
    }

    void evict() {
        keyToNode.erase(head->next->key);
        Node* backup = head->next;
        head->next->next->prev = head;
        head->next = head->next->next;
        delete backup;
    }

public:
    LRUCache(int capacity): capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(!keyToNode.count(key)) {
            return -1;
        }
        Node* cur = keyToNode[key];
        refresh(cur);
        return cur->val;
    }

    void put(int key, int value) { // 3, 3
        if(keyToNode.count(key)) {
            Node* cur = keyToNode[key];
            cur->val = value;
            refresh(cur);
            return;
        }
        if(keyToNode.size() == capacity) {
            evict();
        }
        Node* newNode = new Node(key, value);
        keyToNode[key] = newNode;
        append(newNode);
    }
 };