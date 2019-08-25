#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> anagrams;
    vector<vector<string>> res;

    for (int i = 0; i < strs.size(); ++i) {
        string tmp = strs[i];
        sort(begin(tmp), end(tmp));
        auto it = anagrams.find(tmp);
        if (it != anagrams.end()) {
            it->second.push_back(strs[i]);
        } else {
            vector<string> a = {strs[i]};
            res.push_back(a);
            anagrams.emplace(tmp, &a);
        }
    }

    vector<vector<string>> res;
    for (const auto &i : anagrams) {
        // cout << i.first << " --> ";
        // for (const auto &j : i.second) {
        //     cout << j << " ";
        // }
        // cout << endl;

        res.push_back(i.second);
    }

    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
}