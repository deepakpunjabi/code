/*
    Given an array of integers, 
    find out whether there are two distinct indices i and j in the array 
    such that the absolute difference between nums[i] and nums[j] is at most t 
    and the absolute difference between i and j is at most k.

    Example 1:
    Input: nums = [1,2,3,1], k = 3, t = 0
    Output: true

    Example 2:
    Input: nums = [1,0,1,1], k = 1, t = 2
    Output: true

    Example 3:
    Input: nums = [1,5,9,1,5,9], k = 2, t = 3
    Output: false
    
    Constraints:
    0 <= nums.length <= 2 * 104
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 104
    0 <= t <= 231 - 1
*/

#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

// O(nk)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_multiset<int> elem;

    for (int i=0; i<nums.size(); ++i) {
        if (elem.size() > k) {
            elem.erase(elem.find(nums[i-k]));
        }

        

        for (const auto &j: elem) {
            if (abs(j-nums[i]) <= t) {
                return true;
            }
        }

        elem.insert(nums[i]);
    }

    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<int> elem;

    for (int i=0; i<nums.size(); ++i) {
        if (elem.size() > k) {
            elem.erase(elem.find(nums[i-k]));
        }

        auto it = elem.lower_bound(nums[i]);
        if (abs(j-nums[i]) <= t) {
            return true;
        }

        elem.insert(nums[i]);
    }

    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> elem;
        elem.insert(1e18);
        elem.insert(1e18);

        for (int i=0; i<nums.size(); ++i) {

            auto it = elem.lower_bound(nums[i]);
            if (*it-nums[i] <= t) {
                return true;
            }
            --it;
            if (nums[i]-*it <= t) {
                return true;
            }
            

            elem.insert(nums[i]);
            
            if (elem.size() > k) {
                elem.erase(elem.find(nums[i-k]));
            }
        }

        return false;
    }
