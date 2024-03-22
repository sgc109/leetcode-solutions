class Solution {
    string to2digitsStr(int x) {
        if(x < 10) {
            return "0" + to_string(x);
        }
        return to_string(x);
    }
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(begin(arr), end(arr));

        string ans = "";
        do {
            int hour = arr[0] * 10 + arr[1];
            if(hour > 23) continue;
            int minute = arr[2] * 10 + arr[3];
            if(minute > 59) continue;
            
            ans = to2digitsStr(hour) + ":" + to2digitsStr(minute);
        } while(next_permutation(begin(arr), end(arr)));
        
        return ans;
    }
};