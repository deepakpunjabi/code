#include <array>
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    // if (s.empty()) return s; // both are same
    if (s.length() < 2) return s;
    int start = 0;
    int end = 0;

    int max_len = 0;

    for (int i = 0; i < s.length(); ++i) {
        // odd length string "aba"
        int len1 = expandFromMiddle(s, i, i);
        // even length string "abba"
        int len2 = expandFromMiddle(s, i, i + 1);
        
        int len = max(len1, len2);
        if (len > max_len) {
            max_len = len;
            // as middle is on the left side
            start = i - ((len - 1) / 2);
            end = i + (len / 2);
        }
    }
    // cout << start << max_len << endl;
    return s.substr(start, max_len);
}

int expandFromMiddle(string s, int left, int right) {
    if (s.empty()) return 0;
    if (left > right) return 0;

    while (left >= 0 && right && s[left] == s[right]) {
        --left;
        ++right;
    }

    return right - left - 1;
}

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
