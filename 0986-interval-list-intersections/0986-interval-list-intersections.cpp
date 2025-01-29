class Solution {
    vector<int> getIntersection(vector<int> inter1, vector<int> inter2) {
        if(inter1[0] > inter2[0]) {
            swap(inter1, inter2);
        }
        if(inter1[1] >= inter2[0]) {
            return vector<int>({inter2[0], min(inter1[1], inter2[1])});
        }
        return vector<int>({-1, -1});
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int pos1 = 0;
        int pos2 = 0;
        
        vector<vector<int>> ans;
        while(pos1 < size(firstList) && pos2 < size(secondList)) {
            vector<int> intersect = getIntersection(firstList[pos1], secondList[pos2]);
            if(intersect[0] != -1) {
                ans.push_back(intersect);
            }
            if(firstList[pos1][1] < secondList[pos2][1]) {
                ++pos1;
            } else {
                ++pos2;
            }
        }
        
        return ans;
    }
};