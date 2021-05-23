/*

    Given an integer value, N, return the Nth Fibonacci number.
    Note: Fibonacci numbers are a number sequence where Fibonacci(N) = Fibonacci(N - 1) + Fibonacci(N - 2). 
    The first two Fibonacci numbers are zero and one.

    Ex: Given the following N…
    N = 2, return 1 (one is the second number in the Fibonnaci sequence).

    Ex: Given the following N…
    N = 3, return 2 (Fibonnaci(3) = Fibonacci(2) + Fibonacci(1) = 1 + 1 = 2).

*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> tc = {
        {},
        {0, 4, 8},
        {1, 2, 3},        // mutliple output possible, go FCFS
        {1, 3, 4, 6},     // -1
        {1, 2, 4, 4, 4},  // duplicate values but sorted
    };                    // empty array

    for (auto &i : tc) {
        // cout << indexEqualsValue(i) << endl;
    }

    return 0;
}
