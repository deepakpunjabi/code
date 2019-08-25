// https://www.hackerrank.com/challenges/luck-balance
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void printPairVec(vector<pair<int, int>> arr) {
    for (auto i : arr) {
        cout << i.first << " " << i.second << "\t";
    }
    cout << endl;
}

int main() {
    int n, k, i;
    cin >> n >> k;
    int luck, imp;
    int luckGained = 0;

    vector<pair<int, int>> luckImp;

    for (i = 0; i < n; ++i) {
        cin >> luck >> imp;
        luckImp.emplace_back(luck, imp);
    }

    sort(begin(luckImp), end(luckImp), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    // printPairVec(luckImp);

    for (auto i : luckImp) {
        if (k <= 0 && i.second == 1) {
            luckGained -= i.first;
            continue;
        }
        if (i.second == 1) {
            --k;
        }
        luckGained += i.first;
    }

    cout << luckGained << endl;
    return 0;
}
