#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<char> st;
    // hello segfault
    cout << st.top();
}
