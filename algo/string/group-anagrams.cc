/* 

lid: https://leetcode.com/problems/group-anagrams

Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> anagrams;

    for (const auto &s : strs) {
        string tmp(s);
        sort(tmp.begin(), tmp.end());

        /* 
            if anagram is aleady there, add it with it's buddies
            otherwise create new anagram
        */
        auto it = anagrams.find(tmp);
        if (it != anagrams.end()) {
            it->second.push_back(s);
        } else {
            anagrams.emplace(tmp, vector<string>{s});
        }
    }

    // go through map and formulate res
    for (const auto &a : anagrams) {
        res.push_back(a.second);
    }

    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
}

/* 

    Time Complexity: 
    - O(n) for travesing over n input string
        - O(mlogm) for sorting each string, we can consider this as constant if each string is of fixed size
    - O(k) for iterating over resultant anagrams map, where k <= n
    = O(nmlogm) / quadratic

*/
