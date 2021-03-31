/*

    Given a string s, return the first non-repeating character in it and return its index. 
    If it does not exist, return -1.

    Example 1:
    Input: s = "leetcode"
    Output: 0

    Example 2:
    Input: s = "loveleetcode"
    Output: 2

    Example 3:
    Input: s = "aabb"
    Output: -1
    
    Constraints:
    - 1 <= s.length <= 105
    - s consists of only lowercase English letters.

*/

#include <string>
#include <unordered_map>
using namespace std;

// what if string also has special chars? -> isalpha(i)
// what if string also has upper case letters -> discuss with interviewver
// what if string has whitespaces? 
int firstUniqChar(string s) {
    // you can use vector<int> counts(26, 0) as well.
    unordered_map<char, int> counts;

    for (const auto &i : s) {
        counts[i] += 1;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (counts[s[i]] == 1) return i;
    }

    return -1;
}
