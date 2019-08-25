#include <iostream>
#include <vector>

using namespace std;

// print vector using begin() iterator
void print(vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

// print vector using range iterator
void printRange(vector<int>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // declaration of vector container
    vector<int> myvector{1, 2, 3, 4, 5};

    print(myvector);
    printRange(myvector);

    return 0;
}