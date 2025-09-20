#include <algorithm>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    return search(root, p, q);
  }

  TreeNode *search(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    if (!p || !q) {
      return nullptr;
    }

    if (min(p->val, q->val) > root->val) {
      return search(root->right, p, q);
    } else if (max(p->val, q->val) < root->val) {
      return search(root->left, p, q);
    }
    return root;
  }
};
