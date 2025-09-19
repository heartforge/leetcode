#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {}

  vector<int> dfs(vector<int> &coins, int amount, int i, int quantity) {

    if (amount < 0) {
      return {-1, quantity};
    }
    if (amount == 0) {
      return {1, quantity};
    }

    vector<int> skip = dfs(coins, amount, i + 1, quantity);
    vector<int> take = dfs(coins, amount - coins[i], i, quantity + 1);
  }
};
