class LRUCache {
    unordered_map<int,int> hashMap; // {3: 3, 4: 4}
    unordered_map<int,int> counter; // {1: 1, 2: 1, 3: 2, 4: 2}
    queue<int> q; // [3, 2, 4, 1, 3, 4]
    int cap; // 2
    void refresh(int key) {
        q.push(key);
        counter[key]++;
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    // [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

    int get(int key) { // 4
        if(hashMap.count(key)) {
            refresh(key);
            return hashMap[key];
        } else {
            return -1;
        }
    } // 1, -1, -1, 3, 4
    
    void put(int key, int value) { // 3, 3
        if(hashMap.count(key) == 0 && hashMap.size() == cap) {
            while(true) {
                int frontKey = q.front(); // 1
                q.pop();
                counter[frontKey]--;
                if(counter[frontKey] == 0) {
                    hashMap.erase(frontKey);
                    break;
                }
            }
        }
        refresh(key);
        hashMap[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */