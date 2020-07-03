/* 
Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.

For example, given n = 3, a solution set is :
    [
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
    ]
*/

#include <string>
#include <vector>

using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;
}

void backtrack(vector<string> &res, string curr, int open, int close, int max) {
    // closing condition
    if (curr.length() == max * 2) {
        res.push_back(curr);
        return;
    }
    // track opens (
    if (open < max) backtrack(res, curr + "(", open + 1, close, max);
    // track closes )
    if (close < open) backtrack(res, curr + ")", open, close + 1, max);
}
