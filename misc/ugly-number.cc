/* 

    Write a program to check whether a given number is an ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

    Example 1:
    Input: 6
    Output: true
    Explanation: 6 = 2 × 3

    Example 2:
    Input: 8
    Output: true
    Explanation: 8 = 2 × 2 × 2

    Example 3:
    Input: 14
    Output: false 
    Explanation: 14 is not ugly since it includes another prime factor 7.

    Note:
    - 1 is typically treated as an ugly number.
    - Input is within the 32-bit signed integer range: [−231,  231 − 1].

*/

/* 
    After division by 2, 3 & 5: num should become 1.
*/
bool isUgly(int num) {
    if (num < 1) return false;
    if (num < 7) return true;

    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;

    return num == 1;
}

/* 
    Test Case:
    1, -1, 0, 8, 11

    Time Complexity: O(logn) as at worst case we will be diving input by 2
*/
