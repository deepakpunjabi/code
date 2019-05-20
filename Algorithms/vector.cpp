#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &mv)
{
    for (auto it = mv.begin(); it != mv.end(); ++it)
    {
        cout << ' ' << *it;
    }
}

int main()
{
    // declaration of vector container
    vector<int> myvector{1, 2, 3, 4, 5};

    print(myvector);
    // using begin() to print vector

    return 0;
}