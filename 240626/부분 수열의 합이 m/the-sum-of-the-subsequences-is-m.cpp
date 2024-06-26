#include <iostream>

#define MAX_N 101
#define MAX_M 10001
#define MAX_ANS 100000

using namespace std;

int n,m;
int a[MAX_N];
int dp[MAX_M];

void Init(){
    for(int i=0; i<=m;i++){
        dp[i] = MAX_ANS; 
    }
    dp[0] = 0;
}


int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    Init();

    for(int i=1; i<=n; i++){
        for(int j=m; j>=0;j--){
            if(j>=a[i])
                dp[j] = min(dp[j],dp[j-a[i]]+1);
        }
    }

    int ans = dp[m];
    if(ans == MAX_ANS)
        ans = -1;
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}