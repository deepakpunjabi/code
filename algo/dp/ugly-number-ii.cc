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

/* 
    next ugly number will be last ugly number * 2 or 3 or 5,
    which ever yileds the minimum
    we just need to take for for last eligible index for 2, 3 and 5
*/
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
