class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) { // 3
    // hashMap = {0 -> [3, 0, 1], -1 -> [9], -2 -> [4], 1 -> [8], 2 -> [7]}
    unordered_map<int, vector<int>> hashMap;
        int minColNum = 100, maxColNum = -100; // minColNum = -2, maxColNum = 2
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size() > 0) {
            auto cur = q.front();
            q.pop();
            auto curNode = cur.first;
            int colNum = cur.second;
            if(!curNode) {
                continue;
            }
            // do what should be done
            minColNum = min(minColNum, colNum);
            maxColNum = max(maxColNum, colNum);

            hashMap[colNum].push_back(curNode->val);

            q.push({curNode->left, colNum - 1});
            q.push({curNode->right, colNum + 1});
        }
        
        vector<vector<int>> ans; // [[4], [9], [3, 0, 1], [8], [7]]
        for(int i = minColNum; i <= maxColNum; ++i) { // i = -2
            ans.push_back(hashMap[i]);
        }

        return ans;
    }
};