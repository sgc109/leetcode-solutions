class Solution {
    const int INF = 1e6 + 1;
    vector<int> dp;
    int getMaxHeight(int idx, int shelfWidth, vector<vector<int>>& books) {
        if(idx == books.size()) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        int ans = INF;
        int sumW = 0;
        int maxH = 0;
        for(int i = idx; i < books.size(); ++i) {
            int w = books[i][0];
            int h = books[i][1];
            sumW += w;
            maxH = max(maxH, h);
            
            if(sumW > shelfWidth) {
                break;
            }

            ans = min(ans, maxH + getMaxHeight(i + 1, shelfWidth, books));
        }

        return dp[idx] = ans;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->dp = vector<int>(books.size(), -1);
        return getMaxHeight(0, shelfWidth, books);
    }
};