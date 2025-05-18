#include <iostream>

using namespace std;

#define MAX_N 50

int n;
int dp[MAX_N];

int main(){

    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<MAX_N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}