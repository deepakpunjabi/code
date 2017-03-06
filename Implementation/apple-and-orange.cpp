#include <iostream>
using namespace std;

int main()
{
    int s, t, a, b, m, n, i, tmp;
    cin >> s >> t >> a >> b >> m >> n;

    int apples = 0, oranges = 0;
    for (i = 0; i < m; i++)
    {
        cin >> tmp;
        if (tmp + a >= s && tmp + a <= t)
            ++apples;
    }
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp + b >= s && tmp + b <= t)
            ++oranges;
    }

    cout << apples << endl;
    cout << oranges << endl;
}