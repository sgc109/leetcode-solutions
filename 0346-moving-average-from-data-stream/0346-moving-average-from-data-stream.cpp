class MovingAverage {
    double sum;
    int size;
    queue<int> q;
public:
    MovingAverage(int size): size(size), sum(0.0) {

    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if(q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */