class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); ++i) {
            pq.push(stones[i]);
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