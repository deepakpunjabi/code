/*

Sam's house has an apple tree and an orange tree that yield an abundance of fruit. In the diagram below, the red region denotes his house, where  is the start point and  is the end point. The apple tree is to the left of his house, and the orange tree is to its right. You can assume the trees are located on a single point, where the apple tree is at point  and the orange tree is at point .

Apple and orange(2).png

When a fruit falls from its tree, it lands  units of distance from its tree of origin along the -axis. A negative value of  means the fruit fell  units to the tree's left, and a positive value of  means it falls  units to the tree's right.

Given the value of  for  apples and  oranges, can you determine how many apples and oranges will fall on Sam's house (i.e., in the inclusive range )? Print the number of apples that fall on Sam's house as your first line of output, then print the number of oranges that fall on Sam's house as your second line of output.

Input Format

The first line contains two space-separated integers denoting the respective values of  and . 
The second line contains two space-separated integers denoting the respective values of  and . 
The third line contains two space-separated integers denoting the respective values of  and . 
The fourth line contains  space-separated integers denoting the respective distances that each apple falls from point . 
The fifth line contains  space-separated integers denoting the respective distances that each orange falls from point .

Constraints

Output Format

Print two lines of output:

On the first line, print the number of apples that fall on Sam's house.
On the second line, print the number of oranges that fall on Sam's house.

*/


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