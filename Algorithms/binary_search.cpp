#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    return binary_search(nums, 0, nums.size() - 1, target);
  }

  int binary_search(vector<int> &nums, int left, int right, int target) {
    if (left > right) {
      return -1;
    }

    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target) {
      return binary_search(nums, left, mid - 1, target);
    }
    return binary_search(nums, mid + 1, right, target);
  }

  int binarySearchWithoutRecursion(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int mySqrt(int x) {
  if (x < 2) {
    return x;
  }

  int left = 1;
  int right = x / 2;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int a = x / mid;

    if (mid == a || mid == a - 1) {
      return mid;
    } else if (mid < a) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return left - 1;
}

int main() { cout << mySqrt(4); }