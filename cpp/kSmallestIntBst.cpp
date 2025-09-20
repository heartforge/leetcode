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
  int kthSmallest(TreeNode *root, int k) {
    int i = 0;
    return dfs(root, k, i);
  }

  int dfs(TreeNode *root, int k, int &curInd) {
    if (!root) {
      return -1;
    }

    int l = dfs(root->left, k, curInd);

    curInd++;
    if (curInd == k) {
      return root->val;
    }

    int r = dfs(root->right, k, curInd);

    return max(l, r);
  }
};
