/*

    Given a string s, determine if it is a palindrome, 
    considering only alphanumeric characters and ignoring cases.

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true

    Explanation: "amanaplanacanalpanama" is a palindrome.
    Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.
    
    Constraints:
    - 1 <= s.length <= 2 * 105
    - s consists only of printable ASCII characters.

*/

#include <string>
using namespace std;

bool isPalindrome(string s) {
    int low = 0;
    int high = s.size() - 1;

    while (low < high) {
        // if you use double while loop here then you'll have to maintain i < j as well!
        // this approach is just simpler comparatively
        if (!isalnum(s[low])) {
            ++low;
            continue;
        }
        if (!isalnum(s[high])) {
            --high;
            continue;
        }

        if (tolower(s[low++]) != tolower(s[high--])) return false;
    }

    return true;
}

bool isPalindrome(string s) {
    int low = 0;
    int high = s.size() - 1;

    while (low < high) {
        // similar solve but avoid using continue
        // less code but above approach seems more close to actual logic to me!
        if (!isalnum(s[low])) {
            ++low;
        } else if (!isalnum(s[high])) {
            --high;
        } else if (tolower(s[low++]) != tolower(s[high--])) {
            return false;
        }
    }

    return true;
}
