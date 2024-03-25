#include <iostream>
#include <climits>

#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void Initialize(){

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = INT_MAX;

    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++)
        dp[i][0] = max(dp[i-1][0],arr[i][0]);
    
    for(int j=1; j<n; j++)
        dp[0][j] = max(dp[0][j-1],arr[0][j]);
}

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    
    for(int i=1; i<n;i++)
        for(int j=1; j<n; j++)
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]),arr[i][j]);
   
    cout << dp[n-1][n-1];
        // 여기에 코드를 작성해주세요.
    return 0;
}