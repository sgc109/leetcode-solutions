class MovingAverage {
    double sum;
    int size;
    deque<int> dq;
public:
    MovingAverage(int size): size(size), sum(0.0) {

    }
    
    double next(int val) {
        dq.push_back(val);
        sum += val;
        if(dq.size() > size) {
            sum -= dq.front();
            dq.pop_front();
        }
        return sum / dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */