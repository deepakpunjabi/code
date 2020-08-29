/*
Given a positive integer n, 
find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

#include <unordered_map>
#include <vector>

using namespace std;

// build ways from ground up
// dp[i] = 1 + dp[i - j*j] where j*j <= i
class DP {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int min_ways = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                int curr_ways = 1 + dp[i - j * j];
                min_ways = min(min_ways, curr_ways);
            }
            dp[i] = min_ways;
        }

        return dp[n];
    }
};

class Memoization {
   public:
    int numSquares(int n) {
        unordered_map<int, int> cache;
        return ways(cache, n);
    }

    int ways(unordered_map<int, int> &cache, int n) {
        if (n <= 3) return n;
        auto it = cache.find(n);
        if (it != cache.end()) return it->second;

        int min_ways = n;  // all 1s
        for (int i = 1; i * i <= n; ++i) {
            int curr_ways = 1 + ways(cache, n - i * i);
            min_ways = min(min_ways, curr_ways);
        }

        cache[n] = min_ways;
        return min_ways;
    }
};
