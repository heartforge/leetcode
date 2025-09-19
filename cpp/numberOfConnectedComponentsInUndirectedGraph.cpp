#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
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
    int count = 0;

    unordered_set<int> visit{};
    for (pair<int, vector<int>> node : adjList) {
      if (visit.count(node.first) == 0) {
        bfs(adjList, node.first, visit);
        count++;
      }
    }
    return count;
  }

  void bfs(unordered_map<int, vector<int>> &adjList, int s,
           unordered_set<int> &visit) {
    queue<int> queue;
    queue.push(s);

    while (queue.size() > 0) {
      int qLen = queue.size();
      for (int i = 0; i < qLen; i++) {
        int curr = queue.front();
        queue.pop();

        for (int neighbour : adjList[curr]) {
          if (visit.count(neighbour) == 0) {
            queue.push(neighbour);
            visit.insert(neighbour);
          }
        }
      }
    }
    return;
  }
};
