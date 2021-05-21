/*

    Given a string, text, return how many times you can form the string “programming”.

    Ex: Given the following text…
    text = "mingabcprojklgram", return 1.

    Ex: Given the following text…
    text = "rammingabcprogrammingdefprog", return 2.

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int countProgrammingString(string s) {
    int count = 0;
    string t = "programming";

    // weird things happen when you don't convert size() to int :)
    for (int i = 0; i <= int(s.size()) - int(t.size()); ++i) {
        if (s[i] != t[0]) continue;
        string substr = s.substr(i, t.size());
        if (substr == t) {
            ++count;
        }
    }

    return count;
}

int main() {
    vector<string> tc = {
        "programmin",
        "programming",
        "programminprogrammin",
        "programmingprogrammingprogramming",
        ""};

    for (auto &i : tc) {
        cout << countProgrammingString(i) << endl;
    }

    return 0;
}
