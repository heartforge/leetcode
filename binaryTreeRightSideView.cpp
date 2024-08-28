#include <queue>
#include <vector>
class TreeNode {
public:
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> res;
    std::queue<TreeNode *> queue;
    queue.push(root);

    while (queue.size() > 0) {
      int length = queue.size();
      TreeNode *rightMost = queue.back();
      for (int i = 0; i < length; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        if (node == rightMost) {
          res.push_back(node->val);
        }
        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
    }
    return res;
  }
};
