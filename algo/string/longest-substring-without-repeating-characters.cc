/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int start = 0;
    int end = -1;

    int max_length = 0;
    unordered_map<char, int> unique;

    for (int i = 0; i < s.length(); ++i) {
        auto it = unique.find(s[i]);
        if (it != unique.end()) {
            max_length = max(max_length, end - start + 1);

            int match = it->second;
            // IMP: remove all characters till match as they cannot form max
            // eg abcxyxwz, here anything before x (abc) cannot be part of max window
            for (int j = start; j < match; ++j) {
                unique.erase(s[j]);
            }
            start = match + 1;
            end = i;
            it->second = i;

        } else {
            unique.emplace(s[i], i);
            ++end;
        }
    }

    // it might be that longest window came in the end.
    // you are only updating max_length when duplicate is found
    // eg: aaabcd
    return max(max_length, end - start + 1);
}

/*

test cases:
""
"pwwkew"
"abcaab"
"ohvhjdml"

*/

/*

time complexity: O(n), as we wil only go back till last match
space complexity O(n), if we store whole string in map

*/
