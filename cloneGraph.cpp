#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// Definition for a Node.
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
  Node *cloneGraph(Node *node) {}

  Node *bfs(Node *node) {
    queue<Node *> queue;
    unordered_set<int> visit;
    queue.push(node);
    visit.insert(node->val);

    Node *copyHead = node;
    Node *curr = node;

    while (queue.size() > 0) {
      int length = queue.size();
      for (int i = 0; i < length; i++) {
        Node *cur = queue.front();
        queue.pop();

        for (Node *neighbour : cur->neighbors) {
        }
      }
    }
  }
};
