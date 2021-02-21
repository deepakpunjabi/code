/*

    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

    Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

    Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.

    Constraints:
    0 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.

*/

#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    int start = 0;
    int end = start;

    string original = strs[0];
    bool breached = false;
    for (int j = 0; j < original.size(); ++j) {
        for (int i = 1; i < strs.size(); ++i) {
            if (j == original.size() or j == strs[i].size() or original[j] != strs[i][j]) {
                breached = true;
                break;
            }
        }
        if (breached) {
            break;
        }
        ++end;
    }

    return original.substr(0, end);
}
