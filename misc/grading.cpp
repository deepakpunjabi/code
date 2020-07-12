// https://www.hackerrank.com/challenges/grading

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int g;
        cin >> g;
        
        if(g < 38)
            cout<<g<<endl;
        else{
            if((g+2)/5 > (g/5))
                cout<<(g+2)-((g+2)%5)<<endl;
            else
                cout<<g<<endl;
        }
    }
    return 0;
}
