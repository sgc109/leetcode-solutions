class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int N = arr.size();
        if(N < 3) return false;
        bool down = false;
        for(int i = 0; i < N-1; ++i) {
            if(arr[i] == arr[i+1]) return false;
            if(!down) {
                if(arr[i] > arr[i+1]) {
                    if(i == 0) return false;
                    down = true;
                }
            } else {
                if(arr[i] < arr[i+1]) return false;
            }
        }
        return down;
    }
};