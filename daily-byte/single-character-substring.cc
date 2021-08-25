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
}

int main() {
    vector<vector<int>> tc = {
        {},
        {0, 4, 8},
        {1, 2, 3},
        {1, 3, 4, 6},
        {1, 2, 4, 4, 4},
    };

    for (auto &i : tc) {
        // cout << indexEqualsValue(i) << endl;
    }

    return 0;
}
