#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::map<char, int> sMap;
    std::map<char, int> tMap;
    int len = s.size();

    for (int i = 0; i < len; i++) {
      char currS = s[i];
      char currT = t[i];

      int numS = sMap[currS];
      sMap[currS] = ++numS;

      int numT = tMap[currT];
      tMap[currT] = ++numT;
    }

    if (sMap != tMap) {
      return false;
    }
    return true;
  }
};
