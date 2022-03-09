/*

    Given two binary strings, return their sum (also a binary string).
    The input strings are both non-empty and contains only characters 1 or 0.

    Example 1:
    Input: a = "11", b = "1"
    Output: "100"

    Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"
    
    Constraints:
    - Each string consists only of '0' or '1' characters.
    - 1 <= a.length, b.length <= 10^4
    - Each string is either "0" or doesn't contain any leading zero.

*/

#include <string>
#include <algorithm>

using namespace std;

// without fancy functions
string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        
        string res = "";
        
        int carry = 0;
        while (i >= 0 or j >= 0) {
            int sum = carry;
            
            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';
            
            if (sum > 1) {
                sum -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            
            res += sum + '0';
            
            --i;
            --j;
        }
        
        if (carry) res += '1';
        
        reverse(res.begin(), res.end());
        return res;
    }

string addBinary(string a, string b) {
    string res;
    int carry = 0;

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res += to_string(sum % 2);
        carry = sum / 2;
    }
    if (carry) res += "1";

    reverse(res.begin(), res.end());
    return res;
}

string addBinary1(string a, string b) {
    int carry = 0;
    string str;

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 && j >= 0) {
        int first = a[i--] - '0';
        int second = b[j--] - '0';
        int res = first + second + carry;
        if (res > 1) {
            res -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        str += to_string(res);
    }
    while (i >= 0) {
        int first = a[i--] - '0';
        int res = first + carry;
        if (res > 1) {
            res -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        str += to_string(res);
    }
    while (j >= 0) {
        int first = b[j--] - '0';
        int res = first + carry;
        if (res > 1) {
            res -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        str += to_string(res);
    }
    if (carry) {
        str += "1";
    }

    reverse(str.begin(), str.end());
    return str;
}
