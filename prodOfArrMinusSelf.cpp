#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int totalProd = 1;
        std::vector<int> result;

        // Calculate total product
        for (int i = 0; i < nums.size(); i++) {
            totalProd = totalProd * nums[i];
        }

        // Iterate through vector and divide by current element except in case of 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int zeroProd = 1;
                
                for (int j = 0; j < nums.size(); j++) {
                    if (j == i) {
                        continue;
                    } 
                    zeroProd = zeroProd * nums[j];
                }
                result.push_back(zeroProd);
            } else {
                int currProd = totalProd / nums[i];
                result.push_back(currProd);
            }
        }

        return result;
    }

};
