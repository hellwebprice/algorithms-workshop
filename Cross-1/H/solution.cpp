#include <iostream>
#include <stack>
#include <string>

enum { MOD = 1000000000 + 7 };

bool is_operator(std::string s) { return s == "+" || s == "-" || s == "*"; }

int priority(char op) {
  return op == '+' || op == '-' ? 1 : op == '*' ? 2 : -1;
}

void process_operator(std::stack<int> &integers, char op) {

  int r = integers.top();
  integers.pop();
  int l = integers.top();
  integers.pop();

  switch (op) {
  case '+':
    integers.push(((1LL * l + r) % MOD + MOD) % MOD);
    break;
  case '-':
    integers.push(((1LL * l - r) % MOD + MOD) % MOD);
    break;
  case '*':
    integers.push((1LL * l * r % MOD + MOD) % MOD);
    break;
  }
}

int main(void) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k;
  std::cin >> k;

  std::stack<int> integers;
  std::stack<char> operators;
  for (int i = 0; i < k; ++i) {
    std::string token;
    std::cin >> token;

    if (token == "(") {
      operators.push('(');
      continue;
    }
    if (token == ")") {
      while (operators.top() != '(') {
        process_operator(integers, operators.top());
        operators.pop();
      }
      operators.pop();
      continue;
    }
    if (is_operator(token)) {
      char op = token[0];
      while (!operators.empty() && priority(operators.top()) >= priority(op)) {
        process_operator(integers, operators.top());
        operators.pop();
      }
      operators.push(op);
      continue;
    }
    int number = (std::stoi(token) % MOD + MOD) % MOD;
    integers.push(number);
  }

  while (!operators.empty()) {
    process_operator(integers, operators.top());
    operators.pop();
  }

  std::cout << integers.top() << std::endl;

  return 0;
}
