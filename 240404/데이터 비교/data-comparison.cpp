#include <iostream>
#include <unordered_set>

#define MAX_N 100000
using namespace std;

int n,m;
unordered_set<int> h1;
unordered_set<int> h2;
int arr1[MAX_N];
int arr2[MAX_N];

int main(){

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr1[i];
        h1.insert(arr1[i]);
    }

    cin >> m;

    for(int i=0; i<m; i++){
        cin >> arr2[i];
        h2.insert(arr2[i]);
    }

    for(int i=0; i<m; i++){
        if(h1.find(arr2[i]) != h1.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    return 0;
}