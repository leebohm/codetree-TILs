#include <iostream>

#define MAX_N 100001

using namespace std;

int n,k;
int arr[MAX_N];
int pre_sum[MAX_N];

int main(){
    
    cin >>  n >> k;

    pre_sum[0] = 0;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=n; i++){
        pre_sum[i] = pre_sum[i-1] + arr[i];
    }
    int ans = 0;
    for(int i=k; i<=n; i++){
        ans = max(ans, pre_sum[i]-pre_sum[i-k]);
    }

    cout << ans;

    return 0;
}