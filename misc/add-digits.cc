/*
    Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

    Example:
    Input: 38
    Output: 2 
    Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
                Since 2 has only one digit, return it.

    Follow up:
    Could you do it without any loop/recursion in O(1) runtime?
*/

// logarithmic solution
int addDigits(int num) {
    if (num < 10) return num;

    int res = 0;
    while (num > 0) {
        int digit = num % 10;
        res += digit;
        num /= 10;
    }

    return addDigits(res);
}

// mathematical:
// "The original number is divisible by 9 if and only if the sum of its digits is divisible by 9".
int addDigits(int num) {
    if (num == 0) return 0;
    if (num % 9 == 0) return 9;
    return num % 9;
}
