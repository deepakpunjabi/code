/*

Consider two sets of positive integers,  and . We say that a positive integer, , is between sets  and  if the following conditions are satisfied:

All elements in  are factors of .
 is a factor of all elements in .
Given  and , find and print the number of integers (i.e., possible 's) that are between the two sets.

Input Format

The first line contains two space-separated integers describing the respective values of  (the number of elements in set ) and  (the number of elements in set ). 
The second line contains  distinct space-separated integers describing . 
The third line contains  distinct space-separated integers describing .

Constraints

Output Format

Print the number of integers that are considered to be between  and .

*/

#include <iostream>
#include <vector>
using namespace std;

int gcd(int m, int n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int lcm(int m, int n)
{
    return m * (n / gcd(m, n));
}

int gcdm(vector<int> l)
{
    if (l.size() == 1)
        return l[0];
    int tmp = gcd(l[0], l[1]);
    for (int i = 2; i < l.size(); ++i)
    {
        tmp = gcd(tmp, l[i]);
    }
    return tmp;
}

int lcmm(vector<int> l)
{
    if (l.size() == 1)
        return l[0];
    int tmp = lcm(l[0], l[1]);
    for (int i = 2; i < l.size(); ++i)
    {
        tmp = lcm(tmp, l[i]);
    }
    return tmp;
}

int getBetweenTwoSets(vector<int> a, vector<int> b)
{
    int x = lcmm(a);
    int y = gcdm(b);
    int res = 0;
    int tmp;

    for (int i = 1; tmp <= y; ++i)
    {
        tmp = x * i;
        if (y % tmp == 0)
            ++res;
    }

    return res;
}

int main()
{
    int n, m;
    int i;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    cout << getBetweenTwoSets(a, b) << endl;
    return 0;
}