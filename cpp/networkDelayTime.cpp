#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // First build the adj list from the list of edges
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 1; i < n + 1; i++) {
      adj[i] = vector<pair<int, int>>();
    }
    for (vector<int> edge : times) {
      int s = edge[0];
      int d = edge[1];
      int w = edge[2];
      adj[s].push_back({d, w});
    }

    // Map of mimum weights for each node
    unordered_map<int, int> shortest;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minHeap;
    minHeap.push({0, k});
    int t = 0;
    while (!minHeap.empty()) {
      pair<int, int> p = minHeap.top();
      minHeap.pop();
      int w1 = p.first;
      int n1 = p.second;

      if (shortest.count(n1) > 0) {
        continue;
      }
      shortest[n1] = w1;
      t = w1;
      for (pair<int, int> p : adj[n1]) {
        int n2 = p.first;
        int w2 = p.second;
        if (shortest.count(n2) == 0) {
          minHeap.push({w1 + w2, n2});
        }
      }
    }

    return shortest.size() == n ? t : -1;
  }
};
