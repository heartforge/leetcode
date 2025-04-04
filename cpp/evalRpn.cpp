#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::unordered_set<std::string> ops;
    ops.insert("+");
    ops.insert("-");
    ops.insert("*");
    ops.insert("/");

    std::string operandOne;
    std::string operandTwo;

    std::stack<std::string> stack;

    for (int i = 0; i < tokens.size(); i++) {
      stack.push(tokens[i]);
      if (ops.find(stack.top()) != ops.end()) {
        int result;

        std::string op = stack.top();
        stack.pop();
        std::string operandTwo = stack.top();
        stack.pop();
        std::string operandOne = stack.top();
        stack.pop();

        if (op == "+") {
          result = stoi(operandOne) + stoi(operandTwo);
        } else if (op == "-") {
          result = stoi(operandOne) - stoi(operandTwo);
        } else if (op == "*") {
          result = stoi(operandOne) * stoi(operandTwo);
        } else if (op == "/") {
          result = stoi(operandOne) / stoi(operandTwo);
        }
        stack.push(std::to_string(result));
      }
    }

    return stoi(stack.top());
  }
};
