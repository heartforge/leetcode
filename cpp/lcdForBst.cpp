class TreeNode {
public:
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (true) {
      if (root->val > p->val && root->val > q->val) {
        root = root->left;
      } else if (root->val < p->val && root->val < q->val) {
        root = root->right;
      } else {
        return root;
      }
    }
  }
};
