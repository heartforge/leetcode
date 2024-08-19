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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    TreeNode* node = new TreeNode(root->val);
    node->left = invertTree(root->right);
    node->right = invertTree(root->left);
    return root;
  }
};
