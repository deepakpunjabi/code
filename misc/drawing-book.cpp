#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, p, res;
    cin >> n >> p;

    if (p % 2 == 0) {
        res = min(p / 2, (n - p) / 2);
    }
    else {
        res = min((p - 1 ) / 2, (n - p + 1) / 2);
    }

    cout << res << endl;
    return 0;
}
