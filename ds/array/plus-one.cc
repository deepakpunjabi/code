/* 

    Given a non-empty array of digits representing a non-negative integer, increment one to the integer.
    The digits are stored such that the most significant digit is at the head of the list, 
    and each element in the array contains a single digit.
    You may assume the integer does not contain any leading zero, except the number 0 itself.

    Example 1:
    Input: [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.

    Example 2:
    Input: [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.

*/

#include <vector>

using namespace std;

// This is a generic solution,
// but this problem specifically can be done with much
// focused approach
vector<int> plusOne(vector<int>& digits) {
    // this case is covered by if (carry)
    // if (digits.empty()) return vector<int> {1};
    // by keeping carry as 1, you don't need to explicitly add 1 into digit with carry as 0
    int carry = 1;

    for (int i = digits.size() - 1; i >= 0; --i) {
        digits[i] += carry;
        if (digits[i] > 9) {
            digits[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
            break;
        }
    }

    if (carry) {
        vector<int> res = {1};
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }

    return digits;
}

// concise approach for specific problem
vector<int> plusOneFast(vector<int>& digits) {
    // if anything is less than 9, add 1 and return
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i] += 1;
            return digits;
        }
        digits[i] = 0;
    }

    // everything was 9, create a new vector with first element as 1 and size = old + 1
    vector<int> res(digits.size() + 1, 0);
    res[0] = 1;
    return res;
}
