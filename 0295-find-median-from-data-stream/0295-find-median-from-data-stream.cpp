class MedianFinder {
    multiset<int> orderedNums;
    multiset<int>::iterator medianPtr = orderedNums.end();
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        orderedNums.insert(num);
        if(medianPtr == orderedNums.end() ||
        (orderedNums.size() % 2 == 0 && num < *medianPtr)) {
            --medianPtr;
        } else if(orderedNums.size() % 2 && num >= *medianPtr) {
            ++medianPtr;
        }
    }
    
    double findMedian() {
        if(orderedNums.size() % 2) {
            return *medianPtr;
        } else {
            return ((*medianPtr) + (*next(medianPtr))) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */