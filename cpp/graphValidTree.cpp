#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    if (edges.size() > n - 1) {
      return false;
    }

    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < n; i++) {
      adjList[i] = vector<int>();
    }
    for (vector<int> edge : edges) {
      int s = edge[0];
      int d = edge[1];
      adjList[s].push_back(d);
      adjList[d].push_back(s);
    }
    unordered_set<int> visit;
    bool valid = dfs(adjList, 0, -1, visit);

    if (!valid || n != visit.size()) {
      return false;
    }
    return true;
  }

  bool dfs(unordered_map<int, vector<int>> &adjList, int s, int parent,
           unordered_set<int> &visit) {
    if (visit.count(s) > 0) {
      return false;
    }

    visit.insert(s);
    for (int neighbour : adjList[s]) {
      if (neighbour == parent) {
        continue;
      }
      bool valid = dfs(adjList, neighbour, s, visit);
      if (!valid) {
        return false;
      }
    }

    return true;
  }
};
