/*

    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
    The number of elements initialized in nums1 and nums2 are m and n respectively. 
    You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

    Example 1:
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]

    Example 2:
    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    
    Constraints:
    - nums1.length == m + n
    - nums2.length == n
    - 0 <= m, n <= 200
    - 1 <= m + n <= 200
    - -109 <= nums1[i], nums2[i] <= 109

*/

#include <vector>
using namespace std;

/*  

    use 3 pointers, fill the result array from back
    whichever is the greater element, should go to the spot

*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = nums1.size() - 1;

    while (i >= 0 and j >= 0) {
        nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
    while (j >= 0 && k >= 0) {  // case where first list has no element: merge([0], 0, [1], 1)
        nums1[k--] = nums2[j--];
    }
}

/*  

    TC: O(m+n)
    SC: O(1)

*/
