#include <iostream>
#include <map>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

bool resExists(vector<vector<int>>& m, vector<int>& r);

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    map<int, vector<int>> elem;
    unordered_set<string> e;

    for (int i = 0; i < nums.size(); ++i) {
        auto j = elem.find(nums[i]);
        if (j == elem.end()) {
            elem[nums[i]] = vector<int>(0);
        }
        elem[nums[i]].push_back(i);
    }

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            int tmp = nums[i] + nums[j];

            const auto& it = elem.find(0 - tmp);
            if (it != elem.end()) {
                for (auto k : it->second) {
                    if (k != i && k != j) {
                        vector<int> a = {nums[i], nums[j], nums[k]};
                        sort(begin(a), end(a));
                        if (resExists(res, a)) continue;
                        res.push_back(a);
                    }
                }
            }
        }
    }

    return res;
}

bool resExists(unordered_set<string>& res, vector<int>& r) {
    stringstream ss;
    ss << r[0] << r[1] << r[2];

    string s = ss.str();
    if (res.find(s) != res.end()) {
        return true;
    }
    res.insert(s);
    return false;
}

int main() {
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> res = threeSum(nums);
    for (const auto& i : res) {
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}