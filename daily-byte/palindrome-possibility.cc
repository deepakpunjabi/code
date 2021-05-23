/*

    Given a string, s, return whether or not some permutation of s could form a palindrome.

    Ex: Given the following string s…
    s = "aeae", return true ("aeea" or "eaae").

    Ex: Given the following string s…
    s = "computer", return false.

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
