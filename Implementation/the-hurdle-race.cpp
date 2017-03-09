/*

Dan is playing a video game in which his character competes in a hurdle race by jumping over  hurdles with heights . He can initially jump a maximum height of  units, but he has an unlimited supply of magic beverages that help him jump higher! Each time Dan drinks a magic beverage, the maximum height he can jump during the race increases by  unit.

Given , , and the heights of all the hurdles, find and print the minimum number of magic beverages Dan must drink to complete the race.

Input Format

The first line contains two space-separated integers describing the respective values of  (the number of hurdles) and  (the maximum height he can jump without consuming any beverages). 
The second line contains  space-separated integers describing the respective values of .

Constraints

Output Format

Print an integer denoting the minimum number of magic beverages Dan must drink to complete the hurdle race.

*/

#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int tmp, max = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > max)
            max = tmp;
    }

    int res = max - k;
    if (res < 0)
        res = 0;
    cout << res << endl;

    return 0;
}