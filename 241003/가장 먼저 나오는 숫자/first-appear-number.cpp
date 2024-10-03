#include <iostream>
using namespace std;

#define MAX_N 100001
int n,m;
int arr[MAX_N];

int LowerBound(int x){
    int left = 0;
    int right = n-1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] >= x){
            right = mid - 1;
            min_idx = min(mid, min_idx);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int UpperBound(int x){
    int left = 0;
    int right = n-1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] > x){
            right = mid - 1;
            min_idx = min(mid, min_idx);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int FindIdx(int x){
    int idx1 = LowerBound(x);
    int idx2 = UpperBound(x);
    if(idx1 == idx2)
        return -1;
    return idx1+1;
}

int main() {
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        int idx = FindIdx(x);
        cout << idx << endl;
    }
    return 0;
}