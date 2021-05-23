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

int main() {
    vector<vector<int>> tc = {
        {},
        {0, 4, 8},
        {1, 2, 3},        // mutliple output possible, go FCFS
        {1, 3, 4, 6},     // -1
        {1, 2, 4, 4, 4},  // duplicate values but sorted
    };                    // empty array

    for (auto &i : tc) {
        // cout << indexEqualsValue(i) << endl;
    }

    return 0;
}
