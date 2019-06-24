#include <iostream>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    vector<int> v = {10, 30, 20};

    make_heap(v.begin(), v.end(), greater<int>());
    // sort(begin(v), end(v), compare);

    for (const auto &i : v) {
        cout << i << endl;
    }
}