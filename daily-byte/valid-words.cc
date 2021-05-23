/*

    Given a string permitted and a string array, words, 
    valid words are strings within words that only contain permitted characters. 
    Return the total number of valid words.

    Ex: Given the following permitted and words…
    permitted = "abc", words = ["d", "ab", "abce"], return 1.

    Ex: Given the following permitted and words…
    permitted = "ake", words = ["ail", "kea", "a"], return 2.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValidWord(unordered_set<char> &chars, string word) {
    for (const auto &i : word) {
        if (chars.find(i) == chars.end()) return false;
    }
    return true;
}

int validWords(string permitted, vector<string> &words) {
    if (permitted.empty()) return 0;
    int result = 0;

    unordered_set<char> chars;
    for (const auto &c : permitted) {
        chars.insert(c);
    }
    for (const auto &i : words) {
        if (isValidWord(chars, i)) {
            ++result;
        }
    }

    return result;
}

int main() {
    vector<pair<string, vector<string>>> tc = {
        {"", {""}},                                      // invalid input, return 0
        {"", {"abc"}},                                   // 0
        {"a", {"a", "b"}},                               // 1
        {"abc", {"ca", "abd", "daaa", "xyz", "abbbc"}},  // 2
        {"aaa", {"a", "aa", "bc", "abc", "aba"}},        // duplicate chars in permitted, 2
    };

    for (auto &i : tc) {
        cout << validWords(i.first, i.second) << endl;
    }

    return 0;
}
