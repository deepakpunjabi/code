#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int i, n, tmp;
	vector<int> type(5,0);

	pair<int, int> max;
	max.first = 0;
	max.second = 0;
	cin >> n;

	for (i = 0; i < n; ++i) {
		cin >> tmp;
		type[tmp - 1] += 1;
	}

	for (i = 0; i < 5; ++i) {
		if (type[i] > max.second) {
			max.second = type[i];
			max.first = i;
		}
	}

	cout << max.first + 1 << endl;
	return 0;
}