#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> mydeque = {10, 20, 30}; 

    mydeque.push_front(111);
    mydeque.emplace_front(222); // don't need to create int as such, mostly used for pair<T1, T2>
    mydeque.push_back(333);

    cout << "mydeque: [ ";
    for (const auto &x : mydeque) {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}
