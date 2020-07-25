/* 
    Given a non-empty array of integers, return the k most frequent elements.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Example 2:
    Input: nums = [1], k = 1
    Output: [1]

    Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// our simple heap based solution
class HeapSolution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        if (k == nums.size()) return nums;

        unordered_map<int, int> freq;
        for (const auto &i : nums) {
            freq[i] += 1;
        }

        // priority queue by default is max heap, so we have to pass reverse comparator
        // have to pass comprator in defination as well as constructor
        auto comp = [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> topk(comp);
        for (const auto &i : freq) {
            if (topk.size() < k) {
                topk.emplace(i.second, i.first);
            } else if (i.second > topk.top().first) {
                topk.pop();
                topk.emplace(i.second, i.first);
            }
        }

        vector<int> res;
        while (!topk.empty()) {
            res.push_back(topk.top().second);
            topk.pop();
        }

            return res;
    }
};

// We can optimize on above solution by not finding top k frequenet element, but only finding kth frequent element.
// Average case is O(n), while worst case being O(n^2), when pivot is choosen in such a way that parition is skewed
class QuickSelectSolution {
    unordered_map<int, int> freq;

   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // find frequencies for all the elements, to use it in compare function in quick select
        for (const auto &i : nums) {
            freq[i] += 1;
        }
         
        // to get top k unique elements, this is our input of all distinct elements
        vector<int> unique;
        for (const auto &i: freq) {
            unique.push_back(i.first);
        }
        
        if (k == unique.size()) return unique;
        quickSelect(unique, 0, unique.size() - 1, unique.size()-k); // we want last k to be sorted
        
        vector<int> res(unique.rbegin(), unique.rbegin()+k);
        return res;
    }

    void quickSelect(vector<int> &curr, int start, int end, int target) {
        if (start >= end) return;

        int pi = partition(curr, start, end, target);
        if (pi == target) {
            return;
        } else if (pi < target) { // we don't need to sort both halves
            return quickSelect(curr, pi + 1, end, target);
        } else {
            return quickSelect(curr, start, pi - 1, target);
        }
    }

    int partition(vector<int> &curr, int start, int end, int target) {
        int pivot = freq[curr[end]];
        int pi = start;

        for (int i=start; i<end; ++i) {
            if (freq[curr[i]] <= pivot) {
                swap(curr[i], curr[pi]);
                ++pi;
            }
        }
        swap(curr[end], curr[pi]);
        return pi;    
    }
    
    void print(vector<int> &a) {
        for (const auto &i: a) {
            cout << i << "-";
        }
        cout << endl;
    }
};

