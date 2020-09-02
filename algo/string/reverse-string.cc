#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReverseString {
   public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        for (int i = 0; i < length / 2; ++i) {
            swap(s[i], s[length - i - 1]);
        }
    }

    void reverseString(string& s) {
        int low = 0;
        int high = s.length() - 1;

        while (low < high) {
            swap(s[low], s[high]);
            ++low;
            --high;
        }
    }
};

int main() {
    string ip[] = {
        "hello",  // long odd length
        "hell",   // long even length
        "he",     // even
        "h",      // odd
        ""        // empty string
    };

    ReverseString rs;
    for (auto& i : ip) {
        // convert string into vector of character using constructor
        // vector<char> vc(i.begin(), i.end());
        cout << "str --> " << i << "\treverse --> ";
        rs.reverseString(i);
        // string s(vc.begin(), vc.end());
        cout << i << endl;
    }
}
