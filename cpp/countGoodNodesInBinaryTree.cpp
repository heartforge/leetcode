//
#include <algorithm>
class TreeNode {
public:
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  int goodNodes(TreeNode *root) { return dfs(root, -10000); }

  int dfs(TreeNode *root, int highestVal) {
    if (!root) {
      return 0;
    }

    highestVal = std::max(highestVal, root->val);
    int leftRes = dfs(root->left, highestVal);
    int currRes = root->val >= highestVal ? 1 : 0;
    int rightRes = dfs(root->right, highestVal);
    return leftRes + currRes + rightRes;
  }
};
