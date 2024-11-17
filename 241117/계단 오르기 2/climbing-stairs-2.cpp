#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n;
int coin[MAXN];
int dp[MAXN][5];

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> coin[i];
    
    dp[1][1] = coin[1];
    dp[2][0] = coin[2];
    dp[2][2] = coin[1] + coin[2];

    for(int i=3; i<=n; i++){
        for(int j=0; j<=3; j++){
            if(dp[i-2][j] != 0)
                dp[i][j] = max(dp[i][j], dp[i-2][j] + coin[i]);
            if(j && dp[i-1][j-1] != 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + coin[i]);
        }
    }

    int ans = 0;
    for(int j=0; j<=3; j++)
        ans = max(ans, dp[n][j]);
    
    cout << ans;
}