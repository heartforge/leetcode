#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, vector<int>> adjList{};
    for (int i = 1; i < numCourses + 1; i++) {
      adjList[i] = vector<int>();
    }
    for (vector<int> edge : prerequisites) {
      int n1 = edge[0];
      int n2 = edge[1];
      adjList[n1].push_back(n2);
    }

    unordered_set<int> visit{};

    for (auto &n : adjList) {
      if (visit.count(n.first) == 0) {
        bool a = dfs(adjList, n.first, visit);
        if (!a) {
          return false;
        }
      }
    }
    return true;
  }

  bool dfs(unordered_map<int, vector<int>> &adjList, int n,
           unordered_set<int> &visit) {
    if (visit.count(n) > 0) {
      return false;
    }

    visit.insert(n);
    for (int neighbour : adjList[n]) {
      bool a = dfs(adjList, neighbour, visit);
      if (!a) {
        return false;
      }
    }
    visit.erase(n);

    return true;
  }
};
