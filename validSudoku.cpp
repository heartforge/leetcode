#include <vector>
#include <set>
#include <map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool isValid = false;
        int len = 9;

        // Iterate through rows
        for (int i = 0; i < len; i ++) {
            std::map<char, int> rowMap;

            // Iterate through cols
            for (int j = 0; j < len; j++) {
                std::map<char, int> colMap;

                
            }

        }
        
        return isValid;
    }

    void getRow(std::vector<char>& board) {

    }
};
