class Solution {
public:
int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<pair<int,int>> points;
		for(int i = 0; i < intervals.size(); i++) {
			vector<int> interval = intervals[i];
			points.push_back({interval[0], 1});
			points.push_back({interval[1], -1});
		}
		sort(points.begin(), points.end());
	
		int ans = 0;
		int cntRoom = 0;
		for(auto p : points) {
			cntRoom += p.second;
			ans = max(ans, cntRoom);
		}
 
		return ans;
    }
};
