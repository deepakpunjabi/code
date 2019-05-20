#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    int i, j;
    int count = 0;
    
    for(i=0; i<N; ++i){
        cin >> a[i];
    }
    
    for(i=0; i<N; ++i) {
        for(j=0; j<N-1-i; ++j) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                count += 1;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
