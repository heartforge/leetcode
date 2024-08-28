class TreeNode {
public:
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {}

  int dfs(TreeNode *root, int k) {
    if (!root) {
      return 0;
    }

    dfs(root->left, k);
    dfs(root->right, k);
  }
};
