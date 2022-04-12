#include <algorithm>
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
        // skip duplicates
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

void print(vector<vector<int>>& res) {
    for (const auto& i : res) {
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0};
    vector<vector<int>> res = threeSum(nums);
    print(res);
}
