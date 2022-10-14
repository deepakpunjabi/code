/*

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

*/

#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int sum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        nums[i] += sum;
        sum = nums[i];
    }

    return nums;
}
