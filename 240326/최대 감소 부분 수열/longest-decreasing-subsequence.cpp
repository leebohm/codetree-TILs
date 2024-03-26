#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n;
int arr[MAX_N];

int dp[MAX_N];

int main(){

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<n; i++){
        dp[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}