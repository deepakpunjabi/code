/*

    Implement strStr().
    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Clarification:
    What should we return when needle is an empty string? This is a great question to ask during an interview.
    For the purpose of this problem, we will return 0 when needle is an empty string. 
    This is consistent to C's strstr() and Java's indexOf().

    Example 1:
    Input: haystack = "hello", needle = "ll"
    Output: 2

    Example 2:
    Input: haystack = "aaaaa", needle = "bba"
    Output: -1

    Example 3:
    Input: haystack = "", needle = ""
    Output: 0

    Constraints:
    - 0 <= haystack.length, needle.length <= 5 * 104
    - haystack and needle consist of only lower-case English characters.

*/

#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;

    for (int i = 0; i < haystack.size(); ++i) {
        if (haystack[i] == needle[0]) {
            int k = i + 1;
            int j = 1;

            while (k < haystack.size() && j < needle.size() && haystack[k] == needle[j]) {
                ++k, ++j;
            }

            if (j == needle.size()) return i;
        }
    }

    return -1;
}

// calling this from inside strStr gives TLE
bool matchString(string haystack, int start, string needle) {
    int i = 1;
    while (start < haystack.size() && i < needle.size()) {
        if (haystack[start] == needle[i]) {
            ++start;
            ++i;
        } else {
            return false;
        }
    }
    return i == needle.size();
}
