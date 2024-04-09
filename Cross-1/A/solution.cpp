#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Record {
  std::string _name;
  std::vector<int> _a;

public:
  Record(const std::string &name, const std::vector<int> &a,
         const std::vector<int> &priorities)
      : _name(name) {
    _a.resize(priorities.size());
    for (int i = 0; i < priorities.size(); ++i) {
      _a[i] = a[priorities[i] - 1];
    }
  }

  bool operator>(const Record &other) const {
    for (int i = 0; i < _a.size(); ++i) {
      if (_a[i] > other._a[i]) {
        return true;
      } else if (_a[i] < other._a[i]) {
        return false;
      }
    }
    return false;
  }

  friend std::ostream &operator<<(std::ostream &os, const Record &record) {
    return os << record._name;
  }
};

int main(void) {

  int n, k;
  std::cin >> n >> k;

  std::vector<int> priorities(k);
  for (auto &priority : priorities) {
    std::cin >> priority;
  }

  std::vector<Record> records;
  records.reserve(n);
  for (int i = 0; i < n; ++i) {
    std::string name;
    std::vector<int> a(k);
    std::cin >> name;
    for (auto &p : a) {
      std::cin >> p;
    }
    records.push_back(Record(name, a, priorities));
  }

  std::sort(records.begin(), records.end(), std::greater<Record>());

  for (auto &record : records) {
    std::cout << record << std::endl;
  }

  return 0;
}
