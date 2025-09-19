#include <functional>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

unordered_map<int, int> shortest(vector<vector<int>> &edges, int n, int src) {
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

vector<pair<int, int>> mst(vector<vector<int>> &edges, int n) {
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

  vector<pair<int, int>> mst{};
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      minHeap{};

  unordered_set<int> visit{};
  visit.insert(1);

  for (pair<int, int> neighbour : adjList[1]) {
    int n1 = neighbour.first;
    int w1 = neighbour.second;
    minHeap.push({w1, 1, n1});
  }

  while (visit.size() < n) {
    tuple<int, int, int> cur = minHeap.top();
    minHeap.pop();
    int w1 = get<0>(cur);
    int n1 = get<1>(cur);
    int n2 = get<2>(cur);

    if (visit.count(n2) > 0) {
      continue;
    }

    mst.push_back({n1, n2});
    visit.insert(n2);

    for (pair<int, int> p : adjList[n2]) {
      int node = p.first;
      int weight = p.second;

      if (visit.count(node) == 0) {
        minHeap.push({weight, n2, node});
      }
    }
  }
  return mst;
}
