#include <algorithm>
#include <cstdlib>
#include <vector>
class TreeNode {
public:
  int val;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val) { this->val = val; }
};

class Solution {
public:
  bool isBalanced(TreeNode *root) { return dfs(root)[0] == 1; }

  std::vector<int> dfs(TreeNode *root) {
    if (!root) {
      return {1, 0};
    }

    std::vector<int> left = dfs(root->left);
    std::vector<int> right = dfs(root->right);

    bool balanced =
        abs(left[1] - right[1]) <= 1 && left[0] == 1 && right[0] == 1;
    int height = 1 + std::max(left[1], right[1]);

    return {balanced ? 1 : 0, height};
  }
};
