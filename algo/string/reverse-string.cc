#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int low = 0;
    int high = s.size() - 1;

    while (low < high) {
        swap(s[low++], s[high--]);
    }
}

int main() {
    string ip[] = {
        "hello",  // long odd length
        "hell",   // long even length
        "he",     // even
        "h",      // odd
        ""        // empty string
    };

    for (auto& i : ip) {
        // convert string into vector of character using constructor
        // vector<char> vc(i.begin(), i.end());
        cout << "str --> " << i << "\treverse --> ";
        reverseString(i);
        // string s(vc.begin(), vc.end());
        cout << i << endl;
    }
}
