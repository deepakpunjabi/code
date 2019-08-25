#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    multimap<int, int> mm = {{1, 1}, {2, 3}, {2, 4}};

    // gives lower_bound iterator for element in multi map
    // useful for finding all elements with same key in multimap
    auto it = mm.lower_bound(2);

    // iterator are always pointers
    while (it->first == 2) {
        cout << it->second << endl;
        ++it;
    }
}