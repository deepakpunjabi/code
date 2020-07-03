#include <iostream>
#include <map>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = 0 - nums[i];
        int low = i + 1;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum == target) {
                vector<int> tmp{nums[i], nums[low], nums[high]};
                res.push_back(tmp);

                // skip the duplicates
                while (low < high && nums[low] == nums[low + 1]) ++low;
                while (low < high && nums[high] == nums[high - 1]) --high;

                ++low;
                --high;
            } else if (sum > target) {
                --high;
            } else {
                ++low;
            }
        }
    }

    return res;
}

// 2 pointers
vector<int> twoSum(vector<int>& nums, int low, int high, int target) {
    while (low < high) {
        int sum = nums[low] + nums[high];
        if (sum == target) {
            return vector<int>{nums[low], nums[high]};
        } else if (sum > target) {
            --high;
        } else {
            ++low;
        }
    }
    return vector<int>{};
}

// ----------------------------------------------------
// bool resExists(vector<vector<int>>& m, vector<int>& r);

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

vector<vector<int>> threeSumTLE(vector<int>& nums) {
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
                        if (resExists(e, a)) continue;
                        res.push_back(a);
                    }
                }
            }
        }
    }

    return res;
}

int main() {
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0};
    vector<vector<int>> res = threeSum(nums);
    for (const auto& i : res) {
        cout << "whoop" << endl;
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
