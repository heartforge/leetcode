#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

unordered_map<int, int> shortestPath(vector<vector<int>> &edges, int n,
                                     int src) {
  unordered_map<int, vector<pair<int, int>>> adjList{};
  for (int i = 1; i < n + 1; i++) {
    adjList[i] = vector<pair<int, int>>{};
  }
  for (vector<int> edge : edges) {
    int s = edge[0];
    int d = edge[1];
    int w = edge[2];
    adjList[s].push_back({d, w});
  }

  unordered_map<int, int> shortest{};
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minHeap{};
  minHeap.push({0, src});

  while (minHeap.size() > 0) {
    pair<int, int> p = minHeap.top();
    minHeap.pop();
    int w1 = p.first;
    int n1 = p.second;

    if (shortest.count(n1) > 0) {
      continue;
    }

    shortest[n1] = w1;
    for (pair<int, int> neighbour : adjList[n1]) {
      int n2 = neighbour.first;
      int w2 = neighbour.second;
      if (shortest.count(n2) == 0) {
        minHeap.push({w2, n2});
      }
    }
  }
  return shortest;
}
