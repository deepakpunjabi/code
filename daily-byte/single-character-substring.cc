/*

    Given a string, s, 
    return the length of the longest substring that only contains one unique character.
    Note: s is non-empty and it is guaranteed there is a single answer.

    Ex: Given the following string s…
    s = "aabc", return 2 ("aa" is length 2).

    Ex: Given the following string s…
    s = "abcabbccabccc", return 3.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// this algorithm does not produce unique substrings
int singleCharacterSubstring(string s) {
    if (s.empty()) return 0;

    int count = 1;
    int res = 0;

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
        } else {
            res += count * (count + 1) / 2;
            count = 1;
        }
    }

    res += count * (count + 1) / 2;
    return res;
}

int main() {
    vector<string> tc = {
        "",
        "a",
        "aa",
        "aaa"
        "abc",
        "abca",
        "aabbccaaa",
    };

    for (auto &i : tc) {
        cout << i << " --> " << singleCharacterSubstring(i) << endl;
    }

    return 0;
}
