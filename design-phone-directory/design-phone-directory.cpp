class PhoneDirectory {
    vector<bool> isIn;
    queue<int> Q;
public:
    PhoneDirectory(int maxNumbers) {
        isIn = vector<bool>(maxNumbers, true);
        Q = queue<int>();
        for(int i = 0; i < maxNumbers; ++i) {
            Q.push(i);
        }
    }
    
    int get() {
        if(Q.empty()) return -1;
        int frt = Q.front();
        Q.pop();
        isIn[frt] = false;
        return frt;
    }
    
    bool check(int number) {
        return isIn[number];
    }
    
    void release(int number) {
        if(!isIn[number]) {
            Q.push(number);
            isIn[number] = true;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */