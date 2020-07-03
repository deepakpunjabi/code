/*

Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

#include <vector>

using namespace std;


/* 
setup 2 pointers at each end.
go inwards from less height.
keep count of max_area at each combination.
*/
int maxArea(vector<int>& height) {
    int max_area = 0;

    int low = 0;
    int high = height.size() - 1;

    while (low < high) {
        // calculate the area covered by low and high
        int min_height = min(height[low], height[high]);
        int area = min_height * (high - low);
        max_area = max(max_area, area);

        if (height[low] < height[high]) {
            ++low;
        } else {
            --high;
        }
    }

    return max_area;
}
