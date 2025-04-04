class TreeNode {
public:
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root) {
      return false;
    }
    if (!subRoot) {
      return true;
    }

    return isSubtree(root->left, subRoot) || isSametree(root, subRoot) ||
           isSubtree(root->right, subRoot);
  }

  bool isSametree(TreeNode *root, TreeNode *subRoot) {
    if (!subRoot && !root) {
      return true;
    }

    if (root && subRoot && root->val == subRoot->val) {
      return isSametree(root->left, subRoot->left) &&
             isSametree(root->right, subRoot->right);
    } else {
      return false;
    }
  }
};
