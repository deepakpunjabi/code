// https://www.hackerrank.com/challenges/caesar-cipher-1
#include <iostream>
using namespace std;

string encode(string s, int k)
{
    char a;
    for (auto &i : s)
    {
        if (isalpha(i))
        {
            a = isupper(i) ? 'A' : 'a';
            i = a + (i - a + k) % 26;
        }
    }
    return s;
}

int main()
{
    int n, k;
    string s;

    cin >> n >> s >> k;
    cout << encode(s, k % 26);
    return 0;
}