#include <iostream>

#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    

    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        int j=0;
        dp[i][j] = dp[i-1][j] + arr[i][j];
    }

    for(int j=1; j<n; j++){
        int i=0;
        dp[i][j] = dp[i][j-1] + arr[i][j];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j <n ;j++ ){
            dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i][j-1] + arr[i][j]);
        }
    }

    cout << dp[n-1][n-1];


    // 여기에 코드를 작성해주세요.
    return 0;
}