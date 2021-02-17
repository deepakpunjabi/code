/* 

    Count the number of prime numbers *less than* a non-negative number, n.

    Example 1:
    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    Example 2:
    Input: n = 0
    Output: 0

    Example 3:
    Input: n = 1
    Output: 0
    
    Constraints:
    0 <= n <= 5 * 106

*/

#include <vector>

using namespace std;

// a bit fancy solution
int countPrimes(int n) {
    vector<bool> primes(n + 1, true);
    int res = 0;

    // we need to go till n because we need to include every prime in result till the end.
    for (long i = 2; i < n; ++i) {
        if (!primes[i]) continue;

        ++res;

        for (long j = i * i; j < n; j += i) {
            primes[j] = false;
        }
    }

    return res;
}

// normal solution
int countPrimes(int n) {
    vector<bool> primes(n + 1, true);
    int res = 0;

    // no need to go till n as max divisor of i is sqrt(i)
    for (long i = 2; i * i < n; ++i) {
        if (!primes[i]) continue;

        for (long j = i * i; j < n; j += i) {
            primes[j] = false;
        }
    }

    for (int i = 2; i < n; ++i) {
        if (primes[i]) {
            ++res;
        }
    }

    return res;
}

/*

n = 6
primes(7, false) = [0,1,2,3,4,5,6]
res=0

[0,1,2,3,4,5,6]
[t,t,t,t,f,t,f]

for i:
i=2
res=1
for j:
    j=4
    primes[4]=false
    j=6
    primes[6]=false
    j=8

i=3
res=2
for j:
    j=9

i=4

i=5
res=3

*/

/*

n=2
primes[3] = [t,t,t]

[0,1,2]
[t,t,t]


*/
