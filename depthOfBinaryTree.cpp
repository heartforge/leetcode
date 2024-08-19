#include <queue>
class TreeNode {
public:
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    int level = 0;
    if (!root) {
      return 0;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (queue.size() > 0) {
      int length = queue.size();

      for (int i = 0; i < length; i++) {
        TreeNode *node = queue.front();
        queue.pop();

        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
      level++;
    }
    return level;
  }
};
