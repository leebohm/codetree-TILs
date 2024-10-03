#include <iostream>

using namespace std;

#define MAX_N 100001

int n,m;
int arr[MAX_N];

int FindIdx(int num){
    int left = 1;
    int right = n;
    int idx = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == num){
            idx = mid;
            break;
        }
        else if(arr[mid] < num){
            left = mid + 1;
        }
        else{
            right = mid-1;
        }
    }
    return idx;
}
int main(){

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        int idx= FindIdx(num);
        cout << idx << endl; 
    }
    return 0;
}