/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include <vector>

using namespace std;

// https://www.youtube.com/watch?v=1R0_7HqNaW0
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());

    // initialize with an invalid value
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (coins[j] <= i) {
                // use the coin: 1, take answer for remaining coins from already calculated subproblem
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            } else {
                // don't need to continue for the remaining columns
                break;
            }
        }
    }

    if (dp[amount] == amount + 1) return -1;
    return dp[amount];
}
