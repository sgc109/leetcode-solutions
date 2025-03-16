class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    int capacity; // 2
    unordered_map<int, Node*> keyToNode;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(0, 0);
        this->tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
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
 
    int get(int key) { // 1
        if(!keyToNode.count(key)) {
            return -1;
        }
        auto target = keyToNode[key];
        refresh(target);
        return target->val;
    }
/*
{
    3: 3
    4: 4
}
h - 3 - 4 - t
*/   
    void put(int key, int value) { // 4,4
        if(keyToNode.count(key)) {
            auto target = keyToNode[key];
            target->val = value;
            refresh(target);
            return;
        }
        if(keyToNode.size() == capacity) {
            auto target = head->next; // 2
            keyToNode.erase(target->key);
            remove(target);
            delete target;
        }
        auto newNode = new Node(key, value);
        keyToNode[key] = newNode;
        append(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */