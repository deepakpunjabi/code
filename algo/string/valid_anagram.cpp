/*

  Given two strings s and t, return true if t is an anagram of s, and false otherwise.

  Example 1:
  Input: s = "anagram", t = "nagaram"
  Output: true

  Example 2:
  Input: s = "rat", t = "car"
  Output: false
  
  Constraints:
  1 <= s.length, t.length <= 5 * 104
  s and t consist of lowercase English letters.
  
  Follow up: What if the inputs contain Unicode characters? 
  How would you adapt your solution to such a case?

*/

#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    // may as well use an unordered_map or a vector
    int index[26] = {};
    for (int i = 0; i < s.size(); ++i) {
        index[s[i] - 'a']++;
        index[t[i] - 'a']--;
    }
    for (int i : index) {
        if (index[i]) return false;
    }
    return true;
}
