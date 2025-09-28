#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int longest = 0;
    int maxL = 0;

    for (int i = 0; i < s.size(); i++) {
      int l = i;
      int r = i;

      while (l >= 0 && r < s.size() && s[l] == s[r]) {
        if ((r - l + 1) > longest) {
          longest = r - l + 1;
          maxL = l;
        }
        l--;
        r++;
      }

      l = i;
      r = i + 1;

      while (l >= 0 && r < s.size() && s[l] == s[r]) {
        if ((r - l + 1) > longest) {
          longest = r - l + 1;
          maxL = l;
        }
        l--;
        r++;
      }
    }

    return s.substr(maxL, longest);
  }
};
