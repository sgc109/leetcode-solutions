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
    vector<int> shortList = N < M ? nums1 : nums2;
    vector<int> longList = N < M ? nums2 : nums1;
    priority_queue<Node> pq;
    for(int i = 0; i < min(k, (int)shortList.size()); ++i) {
      pq.push(Node{shortList[i] + longList[0], i, 0});
    }
    vector<vector<int>> ret;
    while(ret.size() < k && !pq.empty()) {
      Node cur = pq.top();
      pq.pop();
      int ansFirst = shortList[cur.i];
      int ansSecond = longList[cur.j];
      if(N >= M) swap(ansFirst, ansSecond);
      ret.push_back(vector<int>({ansFirst, ansSecond}));
      if(cur.j + 1 < min(k, (int)longList.size())) {
        pq.push(Node{shortList[cur.i] + longList[cur.j + 1], cur.i, cur.j + 1});
      }
    }

    return ret;
  }
};
