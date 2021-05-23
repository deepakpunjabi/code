/*

Given the root of two binary trees, a and b, 
return the resulting tree when you overlay a on top of b.
Note: For any nodes that overlap a is placed on top of b, 
the resulting tree’s node should contain their sum.

Ex: Given the following a and b…

a = 1     b = 4
   / \       / \
  2   3     5   6, return the resulting tree...

           5 (1 + 4)
         /   \
(2 + 5) 7     9 (3 + 6)

Ex: Given the following a and b…
a = 7     b = 9
   / \       /
  2   1     5, return the resulting tree...

         16
        /  \
       7    1

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
