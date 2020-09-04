#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    self_strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(self_strings),end(self_strings));
    return self_strings;
  }
private:
  vector<string>self_strings;
};