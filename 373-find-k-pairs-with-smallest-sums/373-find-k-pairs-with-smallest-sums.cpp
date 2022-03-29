typedef long long ll;

class Solution {
  struct Node {
    int sum;
    int i;
    int j;
    bool operator<(const Node& rhs) const {
      return sum > rhs.sum;
    }
  };
  ll pair2long(pair<int,int> p) {
    return (ll)p.first * 100001 + p.second;
  }
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    unordered_set<ll> visited;
    priority_queue<Node> pq;
    vector<vector<int>> ret;
    pq.push(Node{nums1[0] + nums2[0], 0, 0});
    for(int i = 0; i < k && !pq.empty(); ++i) {
      Node cur = pq.top();
      pq.pop();
      ret.push_back(vector<int>({nums1[cur.i], nums2[cur.j]}));
      if(cur.i + 1 < nums1.size()) {
        auto next = Node{nums1[cur.i + 1] + nums2[cur.j], cur.i + 1, cur.j};
        ll hash = pair2long({next.i, next.j});
        if(visited.count(hash) == 0) {
          visited.insert(hash);
          pq.push(next);
        }
      }
      if(cur.j + 1 < nums2.size()) {
        auto next = Node{nums1[cur.i] + nums2[cur.j + 1], cur.i, cur.j + 1};
        ll hash = pair2long({next.i, next.j});
        if(visited.count(hash) == 0) {
          visited.insert(hash);
          pq.push(next);
        }
      }
      while(pq.size() > k) pq.pop();
    }
    return ret;
  }
};
