#include <vector>
using namespace std;

// I/P: [0,0,1,1,1,2,2,3,3,4]
// O/P: 5, [0,1,2,3,4]
int removeDuplicates(vector<int>& nums) {
  int size = nums.size();
  if (size < 2) {
    return size;
  }

  int pivot = 0, i = 0;
  for (i = 0; i < size; ++i) {
    if (nums[pivot] != nums[i]) {
      nums[++pivot] = nums[i];
    }
  }

  return pivot + 1;
}