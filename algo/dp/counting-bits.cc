/*
    Given a non negative integer number num. 
    For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation 
    and return them as an array.

    Example 1:
    Input: 2
    Output: [0,1,1]

    Example 2:
    Input: 5
    Output: [0,1,1,2,1,2]

    Follow up:
    It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
    But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include <vector>

using namespace std;

/* 

    // figuring out the pattern is the main idea 
    Index : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    num :   0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4
    Do you find the pattern?

    Obviously, this is overlap sub problem, and we can come up the DP solution. 
    For now, we need find the function to implement DP.
    dp[0] = 0; // base case
    dp[1] = dp[0] + 1;
    dp[2] = dp[0] + 1;
    dp[3] = dp[1] +1;
    dp[4] = dp[0] + 1;
    dp[5] = dp[1] + 1;
    dp[6] = dp[2] + 1;
    dp[7] = dp[3] + 1;
    dp[8] = dp[0] + 1;
    ...

    This is the function we get, now we need find the other pattern for the function to get the general function. 
    After we analyze the above function, we can get
    dp[0] = 0;
    dp[1] = dp[1-1] + 1;
    dp[2] = dp[2-2] + 1;
    dp[3] = dp[3-2] +1;
    dp[4] = dp[4-4] + 1;
    dp[5] = dp[5-4] + 1;
    dp[6] = dp[6-4] + 1;
    dp[7] = dp[7-4] + 1;
    dp[8] = dp[8-8] + 1;
    ..

    Obviously, we can find the pattern for above example, so now we get the general function
    dp[index] = dp[index - offset] + 1;

*/
vector<int> countBits(int num) {
    vector<int> dp(num + 1);

    int offset = 1;
    for (int i = 1; i <= num; ++i) {
        if (i == offset * 2) {
            offset *= 2;
        }
        dp[i] = dp[i - offset] + 1;
    }

    return dp;
}

/*
    - any digits which are 2^x has only one 1, n & n-1 is 0 in this case eg 4(100) & 3(001) = 0
    - i & i-1 clears the last bit for digits not 2^x
*/
class Bitwise {
   public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i & (i - 1)] + 1;
        return ret;
    }
};
