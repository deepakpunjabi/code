#include <iostream>
#include <map>

using namespace std;

int main() {
    multimap<int,int> mm = {{1,1}};

    // gives lower_bound iterator for element in multi map
    // useful for finding all elements with same key in multimap
    auto it = mm.lower_bound(1);
    
    // hint is used for efficient insertion
    // insert algorithm will start its search from hint iterator
    // useful for continous insertion
    mm.emplace_hint(it, pair<int, int>(2,2));

    cout << mm.size() << endl;
}