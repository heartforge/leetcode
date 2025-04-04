#include <climits>
class TreeNode {
public:
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  bool isValidBST(TreeNode *root) { return validate(root, LONG_MIN, LONG_MAX); }

  bool validate(TreeNode *root, long left, long right) {
    if (!root) {
      return true;
    }
    if (!(root->val > left && root->val < right)) {
      return false;
    }
    return validate(root->left, left, root->val) &&
           validate(root->right, root->val, right);
  }
};
