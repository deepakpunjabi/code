#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    unordered_map<string, int> values = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
    };

   public:
    int romanToInt(string s) {
        int res = 0;

        int i = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() and values.find(s.substr(i, 2)) != values.end()) {
                // cout << "string " << s.substr(i,2) << " value " << values[s.substr(i,2)] << endl;
                res += values[s.substr(i, 2)];
                i += 2;
            } else {
                // cout << "string " << s.substr(i,1) << " value " << values[s.substr(i,1)] << endl;
                res += values[s.substr(i, 1)];
                i += 1;
            }
        }

        return res;
    }
};
