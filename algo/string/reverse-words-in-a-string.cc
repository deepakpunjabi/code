/* 
    Given an input string, reverse the string word by word.

    Example 1:
    Input: "the sky is blue"
    Output: "blue is sky the"

    Example 2:
    Input: "  hello world!  "
    Output: "world! hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.

    Example 3:
    Input: "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

    Note:
    - A word is defined as a sequence of non-space characters.
    - Input string may contain leading or trailing spaces. Howeveyour reversed string should not contain leading or trailing spaces.
    - You need to reduce multiple spaces between two words to a single space in the reversed string.
    
    Follow up:
    For C programmers, try to solve it in-place in O(1) extra space.
*/

#include <list>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

// apart from this method we can use rbegin() and rend() with substr
class StringStreamSolution {
   public:
    string reverseWords(string s) {
        string res, tmp;
        stringstream ss(s);
        while (ss >> tmp) {
            res = tmp + " " + res;
        }
        if (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};

class StackSolution {
   public:
    string reverseWords(string s) {
        stack<char> st;
        string res;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                st.push(s[i]);
                continue;
            }
            while (!st.empty()) {
                res += st.top();
                st.pop();
            }
            if (!res.empty() && res.back() != ' ') res += ' ';
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        if (!res.empty() && res.back() == ' ') res.pop_back();

        return res;
    }
};

/* 
1. There is not much meaning of list here, you can very well use a vector and traverse it backwards to create res.
2. We are storing copy of whole string, this can be optimized by only using a particular word.
3. We can traverse the original string from back to front.
4. Can it be done via recursion?
*/
class ListSolution {
   public:
    string reverseWords(string s) {
        list<string> res;
        string tmp;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (!tmp.empty()) {
                    res.push_front(tmp);
                    tmp.clear();
                }
                continue;
            }
            tmp.push_back(s[i]);
        }

        if (!tmp.empty()) res.push_front(tmp);

        string str;
        for (const auto &i : res) {
            str += i;
            str += " ";
        }
        if (!str.empty()) str.pop_back();

        return str;
    }
};
