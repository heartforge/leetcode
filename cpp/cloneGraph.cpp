#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {
    unordered_map<Node *, Node *> newToOld;
    return dfs(node, newToOld);
  }

  Node *dfs(Node *node, unordered_map<Node *, Node *> &newToOld) {
    if (!node) {
      return nullptr;
    }
    if (newToOld.count(node) > 0) {
      return newToOld[node];
    }

    Node *copy = new Node(node->val);
    newToOld[node] = copy;
    for (Node *n : node->neighbors) {
      Node *m = dfs(n, newToOld);
      copy->neighbors.push_back(m);
    }

    return copy;
  }
};
