#include <stack>
#include <string>

using namespace std;

// faster
class Solution {
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
                default:
                    return false;
            }
        }

        return st.empty();
    }
};

class Solution1 {
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
