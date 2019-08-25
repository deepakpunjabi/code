#include <iostream>
#include <map>
#include <vector>

using namespace std;

// return true for a > b
// otherwise swap
bool compare(int a, int b) {
    return a > b;
}

void print(vector<int>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {10, 30, 20};

    // create a min heap
    // as by default heap creates max heap
    cout << "create min heap" << endl;
    make_heap(v.begin(), v.end(), greater<int>());
    print(v);
    // reverse sort
    cout << "reverse sort" << endl;
    sort(begin(v), end(v), compare);
    print(v);

    return 0;
}
