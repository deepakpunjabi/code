/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:
Input: 3
Output: 5

Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:
1 <= n <= 19 
*/

#include <vector>

using namespace std;

int numTrees(int n) {
    vector<int> catalan(n + 1, 0);
    catalan[0] = 1;
    catalan[1] = 1;

    for (int i = 2; i < n + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

/* 
Useful links:
- https://www.geeksforgeeks.org/program-nth-catalan-number/
- https://www.youtube.com/watch?v=GgP75HAvrlY
*/
