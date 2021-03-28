#include <unordered_map>
#include <vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    unordered_map<int, int> counts;
    for (const auto& num : nums1) {
        counts[num] += 1;
    }

    for (const auto& num : nums2) {
        if (counts.find(num) != counts.end() && counts[num] != 0) {
            counts[num] -= 1;
            res.push_back(num);
        }
    }

    return res;
}

// Don't use iterator assignment etc
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        unordered_map<int, int> m;
        for (const auto& i : nums1) {
            m[i] += 1;
        }

        for (const auto& i : nums2) {
            auto it = m.find(i);
            if (it != m.end() && it->second != 0) {
                it->second -= 1;
                res.push_back(it->first);
            }
        }

        return res;
    }
};

/*

    tc: O(m+n)
    sc: O(min(m, n)) // only store the shorter array in memory, 
    // result is never considered part of space complexity

*/
