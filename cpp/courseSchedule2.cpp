#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    // Initialize and populate adjList
    unordered_map<int, vector<int>> adjList{};
    for (int i = 0; i < numCourses; i++) {
      adjList[i] = vector<int>{};
    }
    for (vector<int> edge : prerequisites) {
      int s = edge[0];
      int d = edge[1];
      adjList[s].push_back(d);
    }

    // DFS on each pair in the adjList
    unordered_set<int> metaVisit;
    unordered_set<int> visit;
    vector<int> res{};
    for (pair<int, vector<int>> n : adjList) {

      if (!dfs(adjList, n.first, visit, res, metaVisit)) {
        return {};
      }
    }

    return res;
  }

  bool dfs(unordered_map<int, vector<int>> &adjList, int n,
           unordered_set<int> &visit, vector<int> &res,
           unordered_set<int> &metaVisit) {
    if (visit.count(n) > 0) {
      return false;
    }

    visit.insert(n);
    for (int node : adjList[n]) {
      if (!dfs(adjList, node, visit, res, metaVisit)) {
        return false;
      }
    }
    visit.erase(n);

    if (metaVisit.count(n) == 0) {
      metaVisit.insert(n);
      res.push_back(n);
    }
    return true;
  }
};
