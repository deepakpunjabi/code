// https://www.hackerrank.com/challenges/two-characters
#include <iostream>
#include <string>
#include <set>
using namespace std;

string createString(char x, char y, string s)
{
    string res;
    for (auto i : s)
    {
        if (x == i || y == i)
        {
            res += i;
        }
    }
    return res;
}

bool validate(string t)
{
    for (int i = 0; i < t.size() - 1; ++i)
    {
        if (t[i] == t[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int length, j = 0;
    string s;
    set<char> chars;

    cin >> length;
    cin >> s;

    //get all unique chars
    for (auto i : s)
    {
        if (chars.find(i) == chars.end())
        {
            chars.insert(i);
        }
    }

    int charsize = chars.size();
    char charr[charsize];

    //pick two at a time and create string
    for (auto i : chars)
    {
        charr[j++] = i;
    }

    int max = 0;
    for (int i = 0; i < charsize; ++i)
    {
        for (j = i + 1; j < charsize; ++j)
        {
            string tmp;
            tmp = createString(charr[i], charr[j], s);
            if (validate(tmp))
            {
                if (tmp.size() > max)
                {
                    max = tmp.size();
                }
            }
        }
    }

    cout << max << endl;
    return 0;
}