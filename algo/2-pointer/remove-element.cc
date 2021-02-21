#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;

    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
        if (nums[start] == val) {
            swap(nums[start], nums[end]);
            --end;
        } else {
            // only move start after a successfull swap
            // eg [3,3] val=3 shouldn't increament start
            ++start;
        }
    }

    return start;
}
