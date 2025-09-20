#include <limits>
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
  bool isValidBST(TreeNode *root) {
    int maxLimit = numeric_limits<int>::max();
    int minLimit = numeric_limits<int>::min();

    return dfs(root, maxLimit, minLimit);
  }

  bool dfs(TreeNode *root, int maxLimit, int minLimit) {
    if (!root) {
      return true;
    }

    if (root->val >= maxLimit || root->val <= minLimit) {
      return false;
    }
    bool left = dfs(root->left, root->val, minLimit);
    bool right = dfs(root->right, maxLimit, root->val);

    return left && right;
  }
};
