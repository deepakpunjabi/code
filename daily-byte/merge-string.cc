/*

    Given two strings, s and t, merge the two strings together alternating characters starting with s.
    Note: If one string is longer than the other, 
    append the remaining characters of the longer string at the end of the merged string.

    s = "abc", t = "def", return "adbecf".

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string mergeString(string s, string t) {
    string res = "";
    int i = 0;
    for (i = 0; i < s.length() and i < t.length(); ++i) {
        res += s[i];
        res += t[i];
    }
    if (i < s.length()) {
        res += s.substr(i, s.length() - i);
    }
    if (i < t.length()) {
        res += t.substr(i, t.length() - i);
    }
    return res;
}

int main() {
    unordered_map<string, string> tc = {
        {"ab", "cd"},
        {"a", "c"},
        {"", "c"},
        {"", ""},
        {"ab", "cdef"},
        {"abcd", "ef"},
    };
    for (auto &i : tc) {
        cout << mergeString(i.first, i.second) << endl;
    }
}

/*  

    test cases:
    s: "ab", t: "cd" op: acbd
    s=a, t=c op=ac
    s="", t=c op=c
    s="", t="" op=""
    s="ab", t="cdef", op=acbdef
    s="abcd", t="ef" op=aebfcd

*/
