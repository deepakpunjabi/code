#include <array>
#include <iostream>
#include <string>

using namespace std;

// void print(int m[][], int n) {
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << m[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

string longestPalindrome(string s) {
    int n = s.length();

    int center = 1;
    int length = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 2;; ++j) {
            if (i + j >= n || i - j < 0) {
                break;
            }
            if (s[i + j] == s[i - j]) {
                int cur_lenth = 2 * j + 1;
                if (cur_lenth > length) {
                    center = i;
                    length = cur_lenth;
                }
            } else {
                break;
            }
        }
    }

    cout << center << " " << s[center] << " " << length << " " << endl;
    return s;
}

int main() {
    cout << longestPalindrome("aaacda") << endl;
}
