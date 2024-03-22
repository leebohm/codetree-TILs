#include <iostream>

using namespace std;

int n;
int dp[1001];

int main() {

    cin >> n;

    dp[1] = 2;
    dp[2] = dp[1]*2 + 1;
    dp[3] = dp[2]*2 + dp[1]*dp[2];
    dp[4] = dp[3]*2 + dp[2]*dp[2];

    for(int i=5; i<= n; i++){
        dp[i] = (dp[i-1]*2 + dp[i-2]*dp[2]) % 1000000007;
    }
    cout << dp[n];
    // 여기에 코드를 작성해주세요.
    return 0;
}