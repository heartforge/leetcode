#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> queue;
    if (root) {
      queue.push(root);
    }

    while (queue.size() > 0) {
      int qLen = queue.size();
      vector<int> cur;
      for (int i = 0; i < qLen; i++) {
        TreeNode *curNode = queue.front();
        queue.pop();
        cur.push_back(curNode->val);

        if (curNode->left) {
          queue.push(curNode->left);
        }
        if (curNode->right) {
          queue.push(curNode->right);
        }
      }
      res.push_back(cur);
    }
    return res;
  }
};
