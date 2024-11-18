#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int INF = -1e9;
int n,k;
int a[MAXN];
int dp[MAXN][15];

int main(){
    cin >> n >> k;

    for(int i= 1; i<=n; i++)
        cin >> a[i];
    
    int ans = INF;

    for(int i=1; i<=n; i++){
        if(a[i] >= 0){
            for(int j = 0; j<=k; j++){
                dp[i][j] = max(dp[i-1][j] + a[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }

        else{
            for(int j=1; j<=k; j++){
                dp[i][j] = max(dp[i-1][j-1] + a[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    
}