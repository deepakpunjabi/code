/* 
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<char, string> button;

   public:
    Solution() {
        button = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        // while number not found in map
        char first = digits[0];
        auto it = button.find(first);
        if (it != button.end()) {
            string s = it->second;
            for (int i = 0; i < s.length(); ++i) {
                string tmp(1, s[i]);
                res.push_back(tmp);
            }
        }

        for (int i = 1; i < digits.length(); ++i) {
            string tmp = button.find(digits[i])->second;
            for (int j = 0; j < tmp.length(); ++j) {
                string curr(1, tmp[j]);
                for (int k = 0; k < res.size(); ++k) {
                    if (res[k].length() == i) {
                        string next = res[k];
                        next += curr;
                        // cout << "pushing " << next <<endl;
                        res.push_back(next);
                    }
                }
            }
        }

        vector<string> final_res;
        for (const auto &i : res) {
            if (i.length() == digits.length()) {
                final_res.push_back(i);
            }
        }

        return final_res;
    }
};

int main() {
    Solution s;
    cout << s.letterCombinations("23").size() << endl;
}
