#include <iostream>

int n,k;

using namespace std;

int arr[100];
int min_a = 1e9, max_a = 0;
int arr2[100];

bool Check(int temp){

    // temp가 최댓값
    int cnt =1;
    for(int i=0; i<n;i++){
        if(arr[i]<=temp) {
            arr2[cnt++] = i;
            }

    }
    arr2[cnt] = n-1;

    for(int i=1; i<=cnt;i++){
        int dist = abs(arr2[i]-arr2[i-1]);
        if(dist > k){
            return false;
        }
    }
    return true;
}



int main() {
    
    cin >> n >> k;


    for(int i=0; i<n;i++){
        cin >> arr[i];
        min_a = min(arr[i],min_a);
        max_a = max(arr[i],max_a);
    }
    int ans =1e9;
    for(int i=min_a;i<max_a;i++){ 
        if(Check(i)) ans = min(i,ans); 
        else continue;
    }

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}