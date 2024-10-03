#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 10001

int n,m;
int arr[MAX_N];

bool IsPossible(int val){
    int total = 0;
    for(int i=0; i<n; i++){
        total += arr[i] / val;
    }
    return total >= m;
}

int main(){
    
    cin >> n >> m;
    int min_val = INT_MAX;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        min_val = min(min_val, arr[i]);
    }

    int left = 1;
    int right = min_val;
    int k = 0;
    while(left <= right){
        int mid = (left + right)/ 2;
        if(IsPossible(mid)){
            k = max(k, mid);
            left = mid + 1;
        }
        else
            right = mid-1;
    }        
    cout << k;
}