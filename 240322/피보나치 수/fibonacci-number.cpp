#include <iostream>

using namespace std;

int dp[46];
int n;

int main() {

    cin >> n;

    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout << dp[n];


    // 여기에 코드를 작성해주세요.
    return 0;
}