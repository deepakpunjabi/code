/*

    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a number of rows:
    string convert(string s, int numRows);
    
    Example 1:
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

    Example 2:
    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

    Example 3:
    Input: s = "A", numRows = 1
    Output: "A"
    
    Constraints:
    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> res;

        int starcol = numRows - 1; // is it a star column
        for (int i = 0; i < s.length();) {
            if (starcol == 0 or starcol == numRows - 1) {
                res.push_back(s.substr(i, numRows));
                i += numRows;
            } else {
                string curr(numRows, '*');
                curr[starcol] = s[i++];
                res.push_back(curr);
            }
            --starcol;
            if (starcol == 0) {
                starcol = numRows - 1;
            }
        }

        string last = res[res.size() - 1];
        if (last.size() < numRows) {
            for (int i = last.size(); i < numRows; ++i) {
                last += '*';
            }
            res[res.size() - 1] = last;
        }

        // create result by scanning cols one by one
        string resstr = "";
        for (int j = 0; j < numRows; ++j) {
            for (int i = 0; i < res.size(); ++i) {
                if (res[i][j] != '*') {
                    resstr += res[i][j];
                }
            }
        }

        return resstr;
    }
};
