#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// A bracket sequence is considered balanced
// - if for every prefix of the sequence, the number of opening brackets is greater than or equal to the number of closing brackets,
// - and the total number of opening brackets is equal to the number of closing brackets.

// More software engineering related approach
class ValidParens {
    unordered_map<char, char> parens;
    unordered_map<char, char> anti_parens;
    string s;

   public:
    ValidParens(string ip) : s(ip) {
        parens['('] = ')';
        parens['{'] = '}';
        parens['['] = ']';

        anti_parens[')'] = '(';
        anti_parens['}'] = '{';
        anti_parens[']'] = '[';
    }

    bool hasBalancedParens() {
        // clarify if empty input is balanced parens or not
        stack<char> st;
        for (const auto &i : s) {
            // need to ignore non-parenthesis members
            // like alphabets, numebers, comma etc
            if (parens.find(i) != parens.end()) {
                st.push(i);
            }
            if (anti_parens.find(i) != anti_parens.end()) {
                if (st.empty()) return false;
                if (st.top() != anti_parens[i]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

// more competitive programming style faster approach
class ValidParens1 {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (const auto &i : s) {
            switch (i) {
                case '(':
                    st.push('(');
                    break;
                case '[':
                    st.push('[');
                    break;
                case '{':
                    st.push('{');
                    break;
                case '}':
                    if (st.empty()) return false;
                    if (st.top() != '{') {
                        return false;
                    }
                    st.pop();
                    break;
                case ')':
                    if (st.empty()) return false;
                    if (st.top() != '(') {
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if (st.empty()) return false;
                    if (st.top() != '[') {
                        return false;
                    }
                    st.pop();
                    break;
                // does not handle non-parens
                // will generate wrong output
                default:
                    return false;
            }
        }

        return st.empty();
    }
};

// Hacky solve to have less lines of code
class ValidParens2 {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (const auto &i : s) {
            switch (i) {
                case '(':
                case '[':
                case '{':
                    st.push(i);
                    break;
                case '}':
                case ')':
                case ']':
                    if (st.empty()) return false;
                    // this is a hack and idelly you should store a map
                    // to store opposite elements
                    if (st.top() != char(i - 1) && st.top() != char(i - 2)) {
                        return false;
                    }
                    st.pop();
                    break;
                default:
                    return false;
            }
        }

        return st.empty();
    }
};

// test program
int main() {
    string ip[] = {"", "a", "()", "(", "(}", "}", "{{", "}}", "{[abc(h)ac]}"};
    for (const auto &i : ip) {
        ValidParens vp(i);
        cout << boolalpha << "string --> " << i << "\t"
             << "has valid parens ---> " << vp.hasBalancedParens();
        cout << endl;
    }
}
