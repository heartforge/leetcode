#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int indA = 0;
        int indB = s.size()-1;

        while (indA < indB) {
            while (!isalnum(s[indA]) && indA < indB) {
                indA += 1;
            }
            while (!isalnum(s[indB]) && indA < indB) {
                indB -= 1;
            }

            if (std::tolower(s[indA]) != std::tolower(s[indB])) {
                  return false;
            }
            indA++;
            indB--;
        }
        return true;
    }
};
