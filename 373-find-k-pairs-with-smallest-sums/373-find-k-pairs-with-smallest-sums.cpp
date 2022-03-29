class Solution {
  struct Node {
    int sum;
    int i;
    int j;
    bool operator<(const Node& rhs) const {
      return sum > rhs.sum;
    }
  };
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int N = nums1.size();
    int M = nums2.size();
    priority_queue<Node> pq;
    for(int i = 0; i < N; ++i) {
      pq.push(Node{nums1[i] + nums2[0], i, 0});
    }
    vector<vector<int>> ret;
    while(ret.size() < k && !pq.empty()) {
      Node cur = pq.top(); // (12,1,0)
      pq.pop();
      vector<int> toPush({nums1[cur.i], nums2[cur.j]});
      ret.push_back(toPush);
      if(cur.j + 1 < M) {
        pq.push(Node{nums1[cur.i] + nums2[cur.j + 1], cur.i, cur.j + 1});
      }
    }

    return ret;
  }
};
