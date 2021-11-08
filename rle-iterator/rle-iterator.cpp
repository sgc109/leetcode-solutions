class RLEIterator {
    struct Chunk {
        int num;
        int cnt;
    };
    vector<Chunk> chunks;
    int pos;
public:
    RLEIterator(vector<int>& encoding) {
        int N = encoding.size();
        chunks.resize(N/2);
        for(int i = 0; i < N/2; ++i) {
            chunks[i] = Chunk{encoding[2*i+1], encoding[2*i]};
        }
        pos = 0;
    }
    
    int next(int n) {
        int last = -1;
        while(n > 0 && pos < chunks.size()) {
            last = chunks[pos].num;
            int dec = min(chunks[pos].cnt, n);
            chunks[pos].cnt -= dec;
            n -= dec;
            if(chunks[pos].cnt == 0) ++pos;
        }
        if(n > 0) return -1;
        return last;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
