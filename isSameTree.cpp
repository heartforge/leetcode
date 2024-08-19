class TreeNode {
public:
  int val;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val) {
    this->val = val;
  }
};

class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    } else if (!p && q) {
      return false;
    } else if (p && !q) {
      return false;
    }

    bool left = isSameTree(p->left, q->left);
    bool curr = p->val == q->val;
    bool right = isSameTree(p->right, q->right);
    return left && curr && right;
  }
};
