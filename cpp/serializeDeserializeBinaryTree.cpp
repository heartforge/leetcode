#include <queue>
#include <string>
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

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string res{stoi(root->val, nullptr, 10)} queue<TreeNode *> q;
    q.push(root);

    while (q.size() > 0) {
      int qLen = q.size();
      for (int i = 0; i < qLen; i++) {
        TreeNode *curr = q.front();
        q.pop();

        if (curr->left) {
          res.append()
        }
      }
    }
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {}
};
