/*

    You are given two strings word1 and word2.
    Merge the strings by adding letters in alternating order, starting with word1.
    If a string is longer than the other, append the additional letters onto the end of the merged string.

    Return the merged string.

    Example 1:
    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r

    Example 2:
    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
    Explanation: Notice that as word2 is longer, "rs" is appended to the end.
    word1:  a   b 
    word2:    p   q   r   s
    merged: a p b q   r   s

    Example 3:
    Input: word1 = "abcd", word2 = "pq"
    Output: "apbqcd"
    Explanation: Notice that as word1 is longer, "cd" is appended to the end.
    word1:  a   b   c   d
    word2:    p   q 
    merged: a p b q c   d

    Constraints:
    - 1 <= word1.length, word2.length <= 100
    - word1 and word2 consist of lowercase English letters.

*/

#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";

        int i1 = 0, i2 = 0;
        int size = min(word1.size(), word2.size());
        bool first = true;
        while (i1 < size || i2 < size) {
          if (first) {
            res += word1[i1];
            i1++;
          } else {
            res += word2[i2];
            i2++;
          }
          first = !first;
        }
        if (word1.size() > i1) {
          res += word1.substr(i1, word1.size()-i1);
        }
        if (word2.size() > i2) {
          res += word2.substr(i2, word2.size()-i2);
        }

        return res;
    }
};