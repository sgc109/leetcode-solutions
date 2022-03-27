class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> mymap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mymap.count(val) > 0) {
            return false;
        }
        
        int idx = vals.size();
        mymap[val] = idx;
        vals.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
        auto entry = mymap.find(val);
        if(entry == mymap.end()) {
            return false;
        }
        
        int idx = entry->second;
        mymap[vals.back()] = idx;
        swap(vals[idx], vals[vals.size()-1]);
        vals.pop_back();
        mymap.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int idx = rand() % vals.size();
        
        return vals[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */