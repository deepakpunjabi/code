#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }

    int index[26] = {};
    for (int i = 0; i < s.size(); ++i) {
      index[s[i] - 'a']++;
      index[t[i] - 'a']--;
    }
    for (int i : index) {
      if (index[i]) return false;
    }
    return true;
  }
};

bool isPalindrome(string s) {
  for (int i = 0, j = s.size() - 1; i < j;) {
    if (!isalnum(s[i])) {
      ++i;
      continue;
    }
    if (!isalnum(s[j])) {
      --j;
      continue;
    }

    if (tolower(s[i]) != tolower(s[j])) {
      return false;
    }
    ++i, --j;
  }
  return true;
}

void test() {
    unordered_map<int, int> mmap;
    
}