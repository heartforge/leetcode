/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>
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
  int maxDepth(TreeNode *root) {
    queue<TreeNode *> queue;
    if (root) {
      queue.push(root);
    }

    int level = 0;

    while (queue.size() > 0) {
      int qLen = queue.size();
      level++;
      for (int i = 0; i < qLen; i++) {
        TreeNode *curr = queue.front();
        queue.pop();

        if (curr->left) {
          queue.push(curr->left);
        }
        if (curr->right) {
          queue.push(curr->right);
        }
      }
    }
    return level;
  }
};
