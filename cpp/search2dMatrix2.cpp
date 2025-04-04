#include <iostream>
#include <ostream>
#include <vector>
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int x = matrix.size();
    int y = matrix[0].size();

    int leftX = 0;
    int rightX = x - 1;

    while (leftX < rightX) {
      int middleX = leftX + (rightX - leftX) / 2;
      if (target >= matrix[middleX][0] && target <= matrix[middleX][y - 1]) {

        int leftY = 0;
        int rightY = y - 1;

        while (leftY < rightY) {
          int middleY = leftY + (rightY - leftY) / 2;
          if (target > matrix[middleX][middleY]) {
            leftY = middleY + 1;
          } else if (target < matrix[middleX][middleY]) {
            rightY = middleY - 1;
          } else if (target == matrix[middleX][middleY]) {
            return true;
          } else {
            return false;
          }
        }
      } else if (target < matrix[middleX][0]) {
        rightX = middleX - 1;
      } else if (target > matrix[middleX][y - 1]) {
        leftX = middleX + 1;
      } else {
        std::cout << "Here" << std::endl;
        return false;
      }
    }
    std::cout << "Here2" << std::endl;
    return false;
  }
};
