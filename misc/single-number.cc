#include <numeric>
#include <vector>

using namespace std;

int singleNumber1(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

// This is better approach
int singleNumber(vector<int>& nums) {
    // ask interviewver what should be returned for such case.
    if (nums.empty()) return 0;

    int result = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        // a ^ b ^ a = b
        result ^= nums[i];
    }
    return result;
}
