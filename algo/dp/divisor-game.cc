/*

    Alice and Bob take turns playing a game, with Alice starting first.
    Initially, there is a number n on the chalkboard. 
    On each player's turn, that player makes a move consisting of:
    - Choosing any x with 0 < x < n and n % x == 0.
    - Replacing the number n on the chalkboard with n - x.
    Also, if a player cannot make a move, they lose the game.

    Return true if and only if Alice wins the game, assuming both players play optimally.

    Example 1:
    Input: n = 2
    Output: true
    Explanation: Alice chooses 1, and Bob has no more moves.

    Example 2:
    Input: n = 3
    Output: false
    Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
    
    Constraints:
    - 1 <= n <= 1000

*/

#include <iostream>
#include <unordered_map>
using namespace std;

bool divisorGameBruteForceSimple(int n) {
    for (int i = 1; i <= n / 2; ++i) {
        // if you make this move and Bob loses.
        if (n % i == 0 && !divisorGame(n - i)) {
            return true;
        }
    }

    return false;
}

bool divisorGameBruteForce(int n) {
    if (n == 1) return false;
    if (n == 2) return true;

    for (int i = 1; i <= n / 2; ++i) {
        // if you make this move and Bob loses.
        if (n % i == 0 && !divisorGame(n - i)) {
            return true;
        }
    }

    return false;
}

class Solution {
    unordered_map<int, bool> cache;

   public:
    bool divisorGameMemoization(int n) {
        if (cache.find(n) != cache.end()) return cache[n];
        if (n == 1) return false;
        if (n == 2) return true;

        for (int i = 1; i <= n / 2; ++i) {
            // if you make this move and Bob loses.
            if (n % i == 0 && !divisorGame(n - i)) { // you could have kept a global pointer to who's turn is currently running as well or a func argument
                cache[n] = true;
                return true;
            }
        }

        cache[n] = false;
        return false;
    }
};

// tabulation
/*  
start with base cases dp[1]=false, dp[2]=true
for i, check if any j exists below it such that,
- i%j == 0
- dp[j] = true

then true, otherwise false
*/

// mathematical proof
bool divisorGame(int n) {
    return n % 2 == 0;
}

int main() {
    cout << boolalpha;
    cout << divisorGame(100) << endl;
}
