// https://www.hackerrank.com/challenges/the-grid-search
#include <iostream>
#include <vector>
#define fl(i, start, finish) for (i = start; i < finish; ++i)
using namespace std;

bool patternExists(vector<string> G, vector<string> P)
{
    int i, j, a, b;
    int R, r, C, c;
    bool flag;

    R = G.size();
    C = G[0].size();
    r = P.size();
    c = P[0].size();

    fl(i, 0, R - r + 1)
    {
        fl(j, 0, C - c + 1)
        {
            flag = true;
            fl(a, 0, r)
            {
                fl(b, 0, c)
                {
                    if (G[i + a][j + b] != P[a][b])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int T, R, C, r, c, i, j;
    cin >> T;

    while (T--)
    {
        cin >> R >> C;

        vector<string> G(R);
        fl(i, 0, R)
        {
            cin >> G[i];
        }

        cin >> r >> c;
        vector<string> P(r);
        fl(i, 0, r)
        {
            cin >> P[i];
        }

        string res = (patternExists(G, P)) ? "YES" : "NO";
        cout << res << endl;
    }
    return 0;
}