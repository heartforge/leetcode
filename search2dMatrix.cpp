#include <vector>
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    const int outSize = matrix.size();
    const int inSize = matrix[0].size();

    int outLeft = 0;
    int outRight = outSize - 1;

    while (outLeft <= outRight) {
      int outMiddle = (outLeft + outRight) / 2;
      if (target < matrix[outMiddle][0]) {
        outRight = outMiddle - 1;
      } else if (target > matrix[outMiddle][inSize - 1]) {
        outLeft = outMiddle + 1;
      } else {
        break;
      }
    }

    if (outLeft > outRight) {
      return false;
    }
    int inLeft = 0;
    int inRight = inSize - 1;
    int outMid = (outLeft + outRight) / 2;

    while (inLeft <= inRight) {
      int inMid = (inLeft + inRight) / 2;
      if (target < matrix[outMid][inMid]) {
        inRight = inMid - 1;
      } else if (target > matrix[outMid][inMid]) {
        inLeft = inMid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
