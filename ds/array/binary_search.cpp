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

class RotatedSortedArray {
public:
    int search(vector<int>& nums, int target) {       
      return searchBinary(nums, 0, nums.size()-1, target);
    }
    
    int searchBinary(vector<int>& nums, int left, int right, int target) {
      if (left > right) {
        return -1;
      }
      int mid = left + (right-left)/2;
      if (nums[mid] == target) {
        return mid;
      } 
      if (int res = searchBinary(nums, left, mid-1, target); res != -1) {
        return res;
      }
      return searchBinary(nums, mid+1, right, target);
    }
};

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class GuessNumber {
public:
    int guessNumber(int n) {
      int left = 1, right=n; 
      
      while (true) {
        int num = left + (right-left)/2;
        int res = guess(num);
        
        if (!res) {
          return num;
        } else if (res > 0) {
          left = num + 1;
        } else {
          right = num -1;
        }
      }
    
    }
};

int main() { cout << mySqrt(4); }