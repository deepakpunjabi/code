/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string],
where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there won't be input like 3a or 2[4].



Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeStringOld(string s) {
    stack<int> counts;
    stack<string> str;

    string curr = "";
    int i = 0;

    while (i < s.length()) {
        if (isdigit(s[i])) {
            int start = i;
            int len = 0;

            while (isdigit(s[i])) {
                ++len;
                ++i;
            }
            string number = s.substr(start, len);
            counts.push(stoi(number));
        } else if (s[i] == '[') {
            str.push(curr);
            curr.clear();
            ++i;
        } else if (s[i] == ']') {
            // if str.empty() {res = ""}
            string res = str.top();
            str.pop();

            int count = counts.top();
            counts.pop();

            while (count--) {
                res += curr;
            }
            curr = res;
            ++i;
        } else {
            curr += s[i];
            ++i;
        }
    }

    return curr;
}

string decodeString(string s) {
    stack<string> st;

    string curr = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '[') {
            st.push(curr);
            curr = "";
        } else if (s[i] == ']') {
            string top1 = st.top();
            cout << top1 << endl;
            int num = stoi(top1);
            st.pop();

            string tmp = "";
            while (num--) {
                tmp += curr;
            }
            st.push(tmp);
            curr = "";
        } else {
            if ((isalpha(curr[0]) && isalpha(s[i])) or (isdigit(curr[0]) && isdigit(s[i]))) {
                curr += s[i];
            } else {
                st.push(curr);
                curr = s[i];
            }
                
        }
        cout << i << " --> " << curr << endl;
    }

    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    return res;
}

int main() {
    string t1 = "3[a]2[bc]";
    string t2 = "3[a2[c]]";
    cout << decodeString(t2) << endl;
}
