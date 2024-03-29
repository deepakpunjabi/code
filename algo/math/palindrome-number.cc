/*

    Given an integer x, return true if x is palindrome integer.
    An integer is a palindrome when it reads the same backward as forward. 
    For example, 121 is palindrome while 123 is not.

    Example 1:
    Input: x = 121
    Output: true

    Example 2:
    Input: x = -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

    Example 3:
    Input: x = 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

    Example 4:
    Input: x = -101
    Output: false
    
    Constraints:
    -231 <= x <= 231 - 1
    
    Follow up: Could you solve it without converting the integer to a string?

*/

bool isPalindrome(int x) {
    // negative numbers are not palindromes as per question
    // 10 is special case for this algorithm
    if (x < 0 or (x % 10 == 0 and x != 0)) return false;
    int rev = 0;

    while (x > rev) {
        int rem = x % 10;
        x /= 10;
        rev = rev * 10 + rem;
    }

    // number is even vs number is odd
    return (x == rev or x == rev / 10);
}
