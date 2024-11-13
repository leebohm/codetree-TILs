#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main() {
    
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        vec.push_back(val);
    }

    sort(vec.begin(), vec.end());
    
    for(int i=0; i<n; i++){
        cout << vec[i] << " ";
    }

    return 0;
}