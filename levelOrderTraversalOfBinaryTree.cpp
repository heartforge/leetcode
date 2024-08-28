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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::queue<TreeNode *> queue;
    std::vector<std::vector<int>> res;
    queue.push(root);

    while (queue.size() > 0) {
      int length = queue.size();
      std::vector<int> currLevelList;

      for (int i = 0; i < length; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        currLevelList.push_back(node->val);

        if (node->left) {
          queue.push(node->left);
        }
        if (node->right) {
          queue.push(node->right);
        }
      }
      res.push_back(currLevelList);
    }
    return res;
  }
};
