class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int& stone : stones) {
            pq.push(stone);
        }
        while(pq.size() >= 2) {
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();
            if(one != two) {
                pq.push(one - two);
            }
        }
        if(pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};