/* 

    Given an integer, n, 
    return the difference between the product and sum of its digits.

    Ex: Given the following n…
    n = 321, return 0 ((3 * 2 * 1) - (3 + 2 + 1).

    Ex: Given the following n…
    n = 56, return 19. 

*/

#include <iostream>
#include <vector>
using namespace std;

int digitArithmetic(int num) {
    if (num == 0) return 0;

    int sum = 0;
    int product = 1;
    while (num > 0) {
        int digit = num % 10;
        cout << digit << endl;
        num /= 10;
        sum += digit;
        product *= digit;
    }

    return product - sum;
}

int main() {
    // should work for negative numbers and zeros as well.
    vector<int> tc = {321, 0, 1111, 1234, 131, -142};
    for (auto &i : tc) {
        cout << digitArithmetic(i) << endl;
    }
}
