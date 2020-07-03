/* There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:
Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:
Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:
cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*  
    idea is that as there are 2^8 possible combination for cells
    and 10^9 days, there must be some cycle where we don't need to 
    calculate in normal way as we already know what next should be.
    We can skip M such cycles which reduces our days significantly.
    important point is, cycle need not start at the 0th day.
    example: for n=101 1-2-3-cycle-cycle-cycle-100-101;
    3 + M*cycle + 2 = N
    ie. remainder = (N-i) % cycle
*/

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    unordered_map<string, int> chart;

    for (int i = 0; i < N; ++i) {
        // we don't need readable string representation, just the data.
        string s(cells.begin(), cells.end());

        auto it = chart.find(s);
        if (it != chart.end()) {
            int cycle = i - it->second;
            int remaining = (N - i) % cycle;
            return prisonAfterNDays(cells, remaining);
        } else {
            chart.emplace(s, i);
            int prev = cells[0];
            for (int j = 1; j < 7; ++j) {
                int next = cells[j + 1];
                int curr = cells[j];
                cells[j] = (prev == next);
                prev = curr;
            }
            // as border cells don't have two adjacent 0's or 1's
            // they can't be 1
            if (i == 0 && cells[0] == 1) cells[0] = 0;
            if (i == 0 && cells[7] == 1) cells[7] = 0;
        }
    }

    return cells;
}
