#include <iostream>

#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void Initialization(){
    dp[0][n-1] = arr[0][n-1];

    for(int i=1; i<n; i++)
        dp[i][n-1] = arr[i][n-1] + dp[i-1][n-1];

    for(int j=n-2; j>=0 ; j--)
        dp[0][j] = arr[0][j] + dp[0][j+1];
}

int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    Initialization();

    for(int i=1; i<n; i++){
        for(int j= n-2; j>=0 ; j--){
            dp[i][j] = min(dp[i][j+1], dp[i-1][j]) + arr[i][j];
            //cout << dp[i][j] << " " << i <<" "<< j << endl;
        }
    }

    cout << dp[n-1][0];

    // 여기에 코드를 작성해주세요.
    return 0;
}