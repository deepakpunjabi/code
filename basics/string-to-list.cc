#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delim) {
    vector<string> res;

    stringstream ss(s);
    string token;
    while (getline(ss, token, delim)) {
        res.push_back(token);
    }

    return res;
}

