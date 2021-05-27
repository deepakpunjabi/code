/*

    Given a string, s, return the length of the longest substring between two characters that are equal.
    Note: s will only contain lowercase alphabetical characters.

    Ex: Given the following string s…
    s = "bbccb", return 3 ("bcc" is length 3).
    
    Ex: Given the following string s…
    s = "abb", return 0.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubstr(string s) {
    if (s.length() < 3) return 0;

    int longest = 0;
    for (int i = 0; i < s.length() - 2; ++i) {  // because only length 3+ can have substr
        for (int j = s.length() - 1; j > i; --j) {
            if (s[i] == s[j]) {
                longest = max(longest, j - i - 1);
            }
        }
    }

    return longest;
}

int main() {
    vector<string> tc = {
        "",  // 0

        "a",  // 0

        "ab",  // 0
        "aa",  // 0

        "abb",  // 0
        "aba",  // 1 - b
        "aaa",  // 1 - a

        "abca",  // 2 - bc
        "abba",  // 2 - bb
        "abab",  // 1 - a

        "abcde",  // 0
        "abcbc",  // 1 - c,b
        "abccb",  // 2 - cc
        "abcca",  // 3 - bcc

    };

    for (auto &i : tc) {
        cout << i << " --> " << longestSubstr(i) << endl;
    }

    return 0;
}
