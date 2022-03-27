class RandomizedSet {
    
    vector<int> elements;
    unordered_map<int, int> val_to_index;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(val_to_index.count(val)) return false;
        val_to_index[val] = elements.size();
        elements.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!val_to_index.count(val)) return false;
        
        int last = elements.back();
        elements.pop_back();
        
        val_to_index[last] = val_to_index[val];
        elements[val_to_index[last]] = last;
        val_to_index.erase(val);
        
        return true;
    }
    
    int getRandom() {
        
        return elements[rand() % elements.size()];
        
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */