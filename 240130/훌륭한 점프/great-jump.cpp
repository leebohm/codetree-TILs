#include <iostream>
#include <algorithm>

#define MAX_N 100
#define MAX_NUM 100

using namespace std;

int n,k;
int arr[MAX_N];

bool IsPossible(int limit){
    int last_idx =0;
    for(int i=1;i<n ;i++){
        if(arr[i] <= limit){
            if(i-last_idx >k)
                return false;
            last_idx =i;
        }
    }
    return true;
}

int main(){
    cin >> n >> k;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=max(arr[0],arr[n-1]);i<=MAX_NUM; i++)
        if(IsPossible(i)){
            cout << i;
            break;
        }
    return 0;
}