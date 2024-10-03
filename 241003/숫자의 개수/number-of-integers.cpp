#include <iostream>

using namespace std;

#define MAX_N 100001
int n,m;
int arr[MAX_N];

int LowerBound(int num){
    int left = 0;
    int right = n-1;
    int min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if( arr[mid] >= num){
            right = mid - 1;
            min_idx = min(min_idx,mid);
        }
        else{
            left = mid + 1;
        }
    }
    return min_idx;
}
int UpperBound(int num){
    int left = 0;
    int right = n-1;
    int max_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] > num){
            right = mid - 1;
            max_idx = min(max_idx, mid);
        }
        else
            left = mid + 1;
    }
    return max_idx;
}

int Count(int num){
    int min_idx = LowerBound(num);
    int max_idx = UpperBound(num);
    int cnt = max_idx - min_idx;
    return cnt;
}
int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        int cnt = Count(num);
        cout << cnt << endl;
    }
    return 0;
}