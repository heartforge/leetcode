#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
      m[s[i]]++;
    }

    for (int j = 0; j < t.size(); j++) {
      m[t[j]]--;
    }

    for (auto e : m) {
      cout << e.first;
      if (e.second != 0) {
        return false;
      }
    }
    return true;
  }
};
