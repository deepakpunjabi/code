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
};

int main() {
    string ip[] = {
        "hello", // long odd length
        "hell", // long even length
        "he", // even
        "h", // odd
        "" // empty string
    };

    ReverseString rs;
    for (const auto& i : ip) {
        // convert string into vector of character using constructor
        vector<char> vc(i.begin(), i.end());
        cout << "str --> " << i << "\treverse --> ";
        rs.reverseString(vc);
        string s(vc.begin(), vc.end());
        cout << s << endl;
    }
}
