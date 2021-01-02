/* 
There is a string, , of lowercase English letters that is repeated infinitely many times. Given an integer, , find and print the number of letter a's in the first  letters of the infinite string.

Example


The substring we consider is , the first  characters of the infinite string. There are  occurrences of a in the substring.

Function Description

Complete the repeatedString function in the editor below.

repeatedString has the following parameter(s):

s: a string to repeat
n: the number of characters to consider
Returns

int: the frequency of a in the substring
Input Format

The first line contains a single string, .
The second line contains an integer, .

Constraints

For  of the test cases, .
Sample Input

Sample Input 0

aba
10
Sample Output 0

7
 */

#include <string>

using namespace std;

long repeatedString(string s, long n) {
    if (s.empty()) return 0;

    long count = 0;
    long i = 0;
    while (n--) {
        if (i == s.size()) {
            count += (n / s.size()) * count;
            n = (n % s.size());
            i = 0;
        }
        if (s[i] == 'a') {
            ++count;
        }
        ++i;
    }

    return count;
}
