// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Coud you solve it without converting the integer to a string?

// Beware of overflow when you reverse the integer.


#include <iostream>
#include <cmath>

using namespace std;

int getLength(int num) {
    int divider = 10;
    int len = 0;

    while (num / divider >= 1) {
        divider *= 10;
        len += 1;
    }

    return len + 1;
}

bool isPalindrome(int x) {
    int len = getLength(x);
    cout << "number length " << len << endl;

    int reverse = 0;
    int first = x;
    for (int i = 0; i < len/2; ++i) {
        reverse = (pow(10, i) * reverse) + (first % 10);
        first /= 10;
    }
    cout << "reverse " << reverse << endl;
    
    int iterations = (len % 2 == 0) ? len/2 : len/2+1;
    first = x / pow(10, iterations);
    cout << "first " << first << endl;

    return first == reverse;
}

int main() {
    cout << isPalindrome(1212) << endl;
}

// Better solution
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long reversed = 0;
        int input = x;
        while (x != 0) {
            int digit = x % 10;
            reversed = (reversed * 10) + digit;
            x /= 10; 
        }
        // cout << "Reversed: " << int(reversed) << endl;
        // cout << "X " << x; 
        if (int(reversed) != input) return false;
        return true;
    }
};

// Better solution 2
class Solution2 {
    bool IsPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber/10;
    }
};