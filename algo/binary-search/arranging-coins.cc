/* 

You have a total of n coins that you want to form in a staircase shape, 
where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
  
Because the 3rd row is incomplete, we return 2.

Example 2:
n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.

 */

#include <iostream>

using namespace std;

int arrageCoins(int n) {
    int low = 0;
    int high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int coins = mid * (mid + 1) / 2;
        if (coins == n) {
            return mid;
        } else if (coins < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}

// O(n) solution
int arrangeCoins1(int n) {
    if (!n) return 0;
    int32_t i = 1;
    int s = 0;
    while (n) {
        n -= i;
        if (n < 0) break;
        ++s;
        ++i;
    }
    return s;
}
