#include <iostream>
#include <climits>

#define MAX_N 1000
using namespace std;

int n;
int a[MAX_N+1];
int dp[MAX_N+1];

void Initialize(){
    for(int i=0; i<=n; i++)
        dp[i] = INT_MIN;

    dp[1] = 1;
    a[0] = 0;
}

int main() {

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    Initialize();

    for(int i=2; i<=n; i++)
        for(int j=1; j<i; j++)
            if(a[i] < a[j])
                dp[i] = max(dp[i], dp[j]+1);

    int ans = 0;

    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
        //cout << dp[i] << " ";
    }

    
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}