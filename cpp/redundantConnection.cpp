#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    int n = edges.size();
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }

    for (vector<int> edge : edges) {
      if (!unionNodes(edge[0], edge[1], parent, rank)) {
        return {edge[0], edge[1]};
      }
    }
    return {};
  }

  int find(int x, unordered_map<int, int> &parent) {
    if (x != parent[x]) {
      parent[x] = find(parent[x], parent);
    }
    return parent[x];
  }

  bool unionNodes(int n1, int n2, unordered_map<int, int> &parent,
                  unordered_map<int, int> &rank) {
    int p1 = find(n1, parent);
    int p2 = find(n2, parent);
    if (p1 == p2) {
      return false;
    }

    if (rank[p1] > rank[p2]) {
      parent[p2] = p1;
    } else if (rank[p1] < rank[p2]) {
      parent[p1] = p2;
    } else {
      parent[p1] = p2;
      rank[p2] += 1;
    }
    return true;
  }
};
