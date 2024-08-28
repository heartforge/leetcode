#include <algorithm>
#include <string>
#include <vector>
class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {}

  void helper(std::vector<std::vector<char>> &board, std::string word, int x,
              int y, std::vector<char> currComb,
              std::vector<std::vector<char>> resComb) {
    if (currComb.size() == word.length()) {
      resComb.push_back(currComb);
      return;
    }
  }
};
