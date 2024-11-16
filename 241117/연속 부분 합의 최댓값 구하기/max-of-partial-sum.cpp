#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 100001
int n;
int arr[MAX_N];
int dp[MAX_N];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    dp[1] = arr[1];
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
    }
    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}