#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n,m;
int arr[MAX_N];

int UpperBound(int target){
    int left = 0;
    int right = n-1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] > target){
            right = mid - 1;
            min_idx = min(min_idx, mid); 
        }
        else{
            left = mid+1;
        }
    }
    return min_idx;
}

int LowerBound(int target){
    int left = 0, right = n-1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] >= target){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        int count = UpperBound(b) - LowerBound(a);
        cout << count << endl;
    }
    return 0;
}