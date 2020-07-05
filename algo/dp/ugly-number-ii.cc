/* 

    Write a program to find the n-th ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

    Example:
    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

    Note:  
    - 1 is typically treated as an ugly number.
    - n does not exceed 1690.

*/

#include <algorithm>

using namespace std;

class SolutionWithIndex {
   public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;

        // index of last element where we can multiply
        // by 2,3 or 5 to get next min element
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int i = 1; i < n; ++i) {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;

            int next = min({next2, next3, next5}); // same as min(next2, min(next3, next4))
            ugly[i] = next;

            if (next == next2) ++i2;
            if (next == next3) ++i3;
            if (next == next5) ++i5;
        }

        return ugly[n - 1];
    }
};

class SolutionWithIndexAndLastValue {
   public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;

        int two = 2;
        int i = 1;

        int three = 3;
        int j = 1;

        int five = 5;
        int k = 1;

        int next_ugly;
        for (int a = 1; a < n; ++a) {
            next_ugly = min(two, min(three, five));
            ugly[a] = next_ugly;

            if (next_ugly == two) {
                two = ugly[i] * 2;
                ++i;
            }
            if (next_ugly == three) {
                three = ugly[j] * 3;
                ++j;
            }
            if (next_ugly == five) {
                five = ugly[k] * 5;
                ++k;
            }
        }

        return ugly[n - 1];
    }
};
