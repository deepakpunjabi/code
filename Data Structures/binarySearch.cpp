#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> a, int low, int high, int key) {
    if(low > high) {
        return -1;
    }
    
    int mid = low + (high - low)/2;
    
    if(key == a[mid]) {
        return mid;
    }
    
    if(key > a[mid]) {
        return binarySearch(a, (mid+1), high, key);    
    } else {
        return binarySearch(a, low, (mid-1), key);
    }
}

int main()
{
    vector<int> a;
    int n, tmp, key, res;
    cin>>n;
    
    for(int i=0; i<n; ++i) {
        cin >> tmp;
        a.push_back(tmp);
    }
    
    cin >> key;
    
    res = binarySearch(a, 0, a.size(), key);
    
    if(res == -1) {
        cout << "key not found" << endl;    
    } else {
        cout << "key found at position: "<< res+1 <<endl;
    }
}
