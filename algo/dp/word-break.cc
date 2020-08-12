/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class WordBreakMemoization {
   public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> words;
        for (const auto &i : wordDict) words.insert(i);

        unordered_map<string, bool> wb;
        wb[""] = true;

        return dfs(s, words, wb);
    }

    bool dfs(string s, unordered_set<string> &words, unordered_map<string, bool> &wb) {
        auto it = wb.find(s);
        if (it != wb.end()) return it->second;
        if (words.find(s) != words.end()) return true;

        for (int l = 1; l < s.length(); ++l) {
            string prefix = s.substr(0, l);
            if (words.find(prefix) != words.end()) {
                wb[prefix] = true;
                string suffix = s.substr(l, s.length() - l);
                wb[suffix] = dfs(suffix, words, wb);
                if (wb[suffix]) return true;
            }
        }

        wb[s] = false;
        return false;
    }
};
