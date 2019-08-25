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
    bool m[n][n];

    int start;
    int len = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                m[i][j] = true;
            } else if (j == i + 1 && s[i] == s[j]) {
                m[i][j] = true;
                start = i;
                len = 2;
            } else {
                m[i][j] = false;
            }
        }
    }

    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (m[i + 1][j - 1] && s[i] == s[j]) {
                m[i][j] = true;
                if (k > len) {
                    start = i;
                    len = k;
                }
            }
        }
    }

    return s.substr(start, len);
}

int main() {
    cout << longestPalindrome("aacda") << endl;
}
