class ZigzagIterator {
    vector<vector<int>> vectors;
    vector<int> ptrs;
    queue<int> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vectors.push_back(v1);
        vectors.push_back(v2);
        ptrs = vector<int>(2, 0);
        if(v1.size() > 0) {
            q.push(0);
        }
        if(v2.size() > 0) {
            q.push(1);
        }
    }

    int next() {
        int vid = q.front();
        q.pop();
        auto v = vectors[vid];

        int ret = v[ptrs[vid]];
        
        ptrs[vid]++;
        if(v.size() > ptrs[vid]) {
            q.push(vid);
        }

        return ret;
    }

    bool hasNext() {
        return q.size() > 0;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */