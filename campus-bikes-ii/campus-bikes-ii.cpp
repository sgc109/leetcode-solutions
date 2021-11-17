class Solution {
    vector<vector<int>> bikes;
    vector<vector<int>> workers;
    int usedBikes;
    int ans = 20000;
    
    int dist(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    void solve(int workerIdx, int sum) {
        if(workerIdx == workers.size()) {
            ans = min(ans, sum);
            return;
        }
        for(int i = 0; i < bikes.size(); ++i) {
            if((usedBikes >> i) & 1) {
                continue;
            }
            usedBikes ^= (1 << i);
            solve(workerIdx+1, sum + dist(workers[workerIdx], bikes[i]));
            usedBikes ^= (1 << i);
        }
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        this->bikes = bikes;
        this->workers = workers;
        
        solve(0, 0);
        
        return ans;
    }
};