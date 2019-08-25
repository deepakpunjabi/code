#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string getModifiedString(string s) {
    int len = s.length();
    if (len < 2) return s;

    string tmp_res, res;
    unordered_set<char> uc;

    for (int i = 0; i < len; ++i) {
        if (uc.find(s[i]) != uc.end()) {
            if (tmp_res.length() > res.length()) {
                res = tmp_res;
            }
            tmp_res = "";
            uc.clear();
            --i;
        } else {
            uc.insert(s[i]);
            tmp_res += s[i];
        }
    }

    if (tmp_res.length() > res.length()) return tmp_res;

    return res;
}

int lengthOfLongestSubstring(string s) {
    int len = s.length();
    if (len < 2) return len;

    string tmp_res, res;
    unordered_map<char, int> uc;
    //unordered_set<char> uc;

    for (int i = 0; i < len; ++i) {
        auto it = uc.find(s[i]);
        if (it != uc.end()) {
            if (tmp_res.length() > res.length()) {
                res = tmp_res;
            }
            tmp_res = "";
            i = it->second;
            uc.clear();
            // --i;
        } else {
            uc.emplace(s[i], i);
            tmp_res += s[i];
        }
    }

    return max(res.length(), tmp_res.length());
}

int main() {
    cout << lengthOfLongestSubstring("dvdf") << endl;
}