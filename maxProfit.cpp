#include <algorithm>
#include <vector>
class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int leftBound = 0;
    int rightBound = 0;
    int maxProfit = 0;

    while (rightBound < prices.size()) {
      if (prices[rightBound] > prices[leftBound]) {
        maxProfit = std::max(maxProfit, prices[rightBound] - prices[leftBound]);
      } else {
        leftBound = rightBound;
      }
      rightBound++;
    }

    return maxProfit;
  }
};
