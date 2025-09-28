#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  string foreignDictionary(vector<string> &words) {
    unordered_map<char, vector<char>> adjList{};
    unordered_map<char, bool> visited{};
    // Initialize adjList
    for (const auto &word : words) {
      for (char ch : word) {
        adjList[ch];
      }
    }

    // Iterate through list of words
    for (int i = 1; i < words.size(); i++) {
      string w1 = words[i - 1];
      string w2 = words[i];

      int minLen = min(w1.size(), w2.size());

      // W2 should not be a prefix of W1
      if (w1.size() > w2.size() &&
          w1.substr(0, minLen) == w2.substr(0, minLen)) {
        return "";
      }
      // Find the first letter that differs between the words
      for (int j = 0; j < minLen; j++) {
        if (w1[j] != w2[j]) {
          adjList[w1[j]].push_back(w2[j]);
          cout << w1[j] << w2[j] << endl;
          break;
        }
      }
    }

    string res;
    for (auto &pair : adjList) {
      if (dfs(pair.first, adjList, visited, res)) {
        return "";
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }

  bool dfs(char currChar, unordered_map<char, vector<char>> &adjList,
           unordered_map<char, bool> &visited, string &res) {
    if (visited.find(currChar) != visited.end()) {
      return visited[currChar];
    }

    visited[currChar] = true;
    for (char neighbour : adjList[currChar]) {
      if (dfs(neighbour, adjList, visited, res)) {
        return true;
      }
    }
    visited[currChar] = false;
    res.push_back(currChar);
    return false;
  }
};
