#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<string, vector<string>> adjList;
    vector<string> list = wordList;
    list.push_back(beginWord);
    int len = 1 + wordList.size();

    for (string word : list) {
      adjList[word] = vector<string>();

      for (string word2 : list) {
        if (word != word2) {
          int diff = diffCount(word, word2);
          if (diff == 1) {
            cout << "Adj:" << word << ":" << word2 << endl;
            adjList[word].push_back(word2);
          }
        }
      }
    }

    int minCount = 1;
    unordered_set<string> visit{};
    queue<string> queue{};
    visit.insert(beginWord);
    queue.push(beginWord);

    while (queue.size() > 0) {
      int qLen = queue.size();
      for (int i = 0; i < qLen; i++) {
        string curr = queue.front();
        queue.pop();

        if (curr == endWord) {
          return minCount;
        }

        for (string neighbour : adjList[curr]) {
          if (visit.count(neighbour) == 0) {
            queue.push(neighbour);
            visit.insert(neighbour);
          }
        }
      }
      minCount += 1;
    }

    return 0;
  }

  int diffCount(string &word1, string &word2) {
    int len = word1.size();
    int count = 0;
    for (int i = 0; i < len; i++) {
      count += (word1[i] != word2[i]);
    }
    return count;
  }
};
