#include <vector>


using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    
    make_heap(v.begin(), v.end());
}