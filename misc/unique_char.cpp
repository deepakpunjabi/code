#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> index;
        for (int i = 0; i < s.size(); ++i) {
            if (auto it = index.find(s[i]); it == index.end()) {
                index.emplace(s[i], i);
            } else {
                it->second = -1;
            }
        }
        pair<char, int> min('a', INT_MAX);
        for (unordered_map<char, int>::const_iterator it = index.begin(); it != index.end(); ++it) {
            if (it->second < min.second) {
                min.first = it->first;
                min.second = it->second;
            }
        }
        cout << min.second << endl;
    }
};