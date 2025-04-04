#include <algorithm>
class TreeNode {
public:
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    int res = 0;
    dfs(root, res);
    return res;
  }

  int dfs(TreeNode *root, int &res) {
    if (!root) {
      return 0;
    }

    int leftLen = dfs(root->left, res);
    int rightLen = dfs(root->right, res);

    res = std::max(res, leftLen + rightLen);
    return 1 + std::max(leftLen, rightLen);
  }
};
