#include <iostream>
#include <string>

int main(void) {

  std::string s, t;
  std::cin >> s >> t;

  auto it_s = s.rbegin();
  for (auto it_t = t.rbegin(); it_t != t.rend(); ++it_t) {
    while (*it_t != *it_s++) {
      if (it_s == s.rend()) {
        while (it_s-- != s.rbegin()) {
          std::cout << "no" << std::endl;
        }
        return 0;
      }
    }
  }

  for (auto it = --it_s; it != s.rend(); ++it) {
    std::cout << "yes" << std::endl;
  }
  for (auto it = it_s; it != s.rbegin(); --it) {
    std::cout << "no" << std::endl;
  }

  return 0;
}
