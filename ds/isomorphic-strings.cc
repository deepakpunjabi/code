/*

    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    All occurrences of a character must be replaced with another character while preserving the order of characters. 
    No two characters may map to the same character, but a character may map to itself.

    Example 1:
    Input: s = "egg", t = "add"
    Output: true

    Example 2:
    Input: s = "foo", t = "bar"
    Output: false

    Example 3:
    Input: s = "paper", t = "title"
    Output: true
    
    Constraints:
    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// here isomorphic means 1-1 mapping
// hence we need to check both ways
bool isIsomorphic(string s, string t) {
    string v(s), u(t);

    unordered_map<char, char> mapping;

    for (int i = 0; i < s.length(); ++i) {
        char first = s[i];
        char second = t[i];

        if (mapping.find(first) == mapping.end()) {
            mapping[first] = second;
        }

        s[i] = mapping[first];
    }

    mapping.clear();
    for (int i = 0; i < u.length(); ++i) {
        char first = u[i];
        char second = v[i];

        if (mapping.find(first) == mapping.end()) {
            mapping[first] = second;
        }

        u[i] = mapping[first];
    }

    return s == t && u == v;
}

// a bit smart solution
bool isIsomorphic(string s, string t) {
    vector<int> m1(256, 0);
    vector<int> m2(256, 0);

    for (size_t i = 0; i < s.size(); i++) {
        // if both counts are diff then one of them has been part of extra mapping
        if (m1[s[i]] != m2[t[i]]) return false;
        
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

/*
s=a, t=b

s=ab, t=cd

s=abab t=cvdt
- cbab [a-c]

m[b] = v
cvab
cvcv

s=abab t=cdcd
*/
