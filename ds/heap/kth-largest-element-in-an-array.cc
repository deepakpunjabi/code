#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    Create min heap
    Store largest k elements in it, skip any elements which are lesser than top of the heap
    Top of the heap is kth largest

    TC: O(nlogk)
    SC: O(k)
*/
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> topk;
    for (const auto& i : nums) {
        if (topk.size() < k) {
            topk.push(i);
        } else if (topk.top() < i) {
            topk.pop();
            topk.push(i);
        }
    }
    return topk.top();
}

int main() {
    vector<int> v = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << findKthLargest(v, k) << endl;
}
