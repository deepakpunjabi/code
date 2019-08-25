#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        unordered_map<int, int> m;
        for (const auto &i: nums1) {
            m[i] += 1;
        }
        
        for (const auto &i: nums2) {
            auto it = m.find(i);
            if ( it != m.end() && it->second != 0) {
                it->second -= 1;
                res.push_back(it->first);
            }
        }
        
        return res;
    }
};