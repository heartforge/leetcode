#include <vector>
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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {}

  vector<int> dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return {0, 0};
    }

    vector<int> left = dfs(root->left, p, q);
    vector<int> right = dfs(root->right, p, q);

    if (left[0] && right[1] || left[1] && right[0]) {
      return;
    }

    int curP = root->val == p->val;
    int curQ = root->val == q->val;

    return {curP, curQ};
  }

  TreeNode *dfs2(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    TreeNode *left = dfs2(root->left, p, q);
    TreeNode *right = dfs2(root->right, p, q);

    bool cur = root->val == p->val || root->val == q->val;
    if (cur && left || cur && right) {
      return root;
    } else if (left && right) {
      return root;
    }

    return nullptr;
  }
};
