class LRUCache {
  int capacity;
  int size;
  int curPriority;
  unordered_map<int, int> hashmap;
  unordered_map<int, int> key2priority;
  map<int, int> priorities;
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->curPriority = 0;
    this->size = 0;
  }
  
  int get(int key) {
    auto item = hashmap.find(key);
    if (item == hashmap.end()) {
      return -1;
    }
    priorities.erase(key2priority[key]);
    priorities[curPriority] = key;
    key2priority[key] = curPriority;

    ++curPriority;

    return item->second;
  }
  
  void put(int key, int value) {
    if(hashmap.count(key) == 0) {
        ++size;
    }
    hashmap[key] = value;
    if(key2priority.count(key)) {
      priorities.erase(key2priority[key]);
    }
    priorities[curPriority] = key;
    key2priority[key] = curPriority;
      
    if (size > capacity) {
      int lruKey = (priorities.begin())->second;
      priorities.erase(priorities.begin());
      key2priority.erase(lruKey);
      hashmap.erase(lruKey);
      --size;
    }
   
    ++curPriority;
  }
};
