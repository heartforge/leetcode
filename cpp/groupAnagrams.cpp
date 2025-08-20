#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;

    for (const auto &str : strs) {
      vector<int> v(26, 0);

      for (char c : str) {
        v[c - 'a']++;
      }
      string key = to_string(v[0]);
      for (int i = 1; i < 26; i++) {
        key += ',' + to_string(v[i]);
      }
      m[key].push_back(str);
    }
    vector<vector<string>> res;
    for (const auto &entry : m) {
      res.push_back(entry.second);
    }
    return res;
  }
};
