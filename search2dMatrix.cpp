#include <vector>
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int leftBound = 0;
    int rightBound = matrix.size()-1;

    while (leftBound <= rightBound) {
      int middle = leftBound + ((rightBound - leftBound) / 2);

      if (search)
      
    }
  }

  bool searchArray(std::vector<int>& array, int target) {
    if (array.size() == 0) {
      return false;
    }

    int leftBound = 0;
    int rightBound = array.size()-1;

    while (leftBound <= rightBound) {
      int middle = leftBound + ((rightBound - leftBound) / 2);

      if (array[middle] < target) {
        leftBound = middle + 1;
      } else if (array[middle] > target) {
        rightBound = middle - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
