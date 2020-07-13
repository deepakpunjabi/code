/* 

    Given a collection of intervals, merge all overlapping intervals.

    Example 1:
    Input: [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

    Example 2:
    Input: [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

#include <vector>

using namespace std;

// compare successive intervals to check if end of first overlaps with start of second
vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) return intervals;

    // sorting is necessary to compare successive intervals
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) {
             return a[0] < b[0];
         });

    vector<vector<int>> res;
    vector<int> curr = {intervals[0][0], intervals[0][1]};
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= curr[1]) {
            // update interval end
            curr[1] = max(intervals[i][1], curr[1]);
        } else {
            res.push_back(curr);
            curr[0] = intervals[i][0];
            curr[1] = intervals[i][1];
        }
    }

    res.push_back(curr);
    return res;
}
