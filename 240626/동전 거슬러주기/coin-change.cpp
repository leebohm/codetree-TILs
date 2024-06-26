#include <iostream>
#include <climits>

#define MAX_N 101
#define MAX_M 10001
using namespace std;

int n,m;
int coin_category[MAX_N];
int dp[MAX_M];

// n개의 동전의 종류가 주어졌을 때, 금액 M을 거슬러 주기 위해 필요한 최소 동전의 수
// 이 문제에서는 동일한 상태라는 걸 정의하기 위한 요소로 지금까지 선택한 동전의 합, 지금까지 사용한 동전의 개수
// 이렇게 두가지를 생각해볼 수 있다. 
// 그 중 지금까지 선택한 동전의 합이 정해졌을 때 지금까지 사용한 동전의 개수를 최소로 하는 점화식을 세워보자. 
// 지금까지 선택한 동전의 합, 지금까지 사용한 동전의 개수가 같으면 아예 동일한 상황인 것을 알 수 있다. 
// 지금까지 선택한 동전의 합이 같다면, 지금까지 사용한 동전의 개수가 적을수록 더 좋다 
// dp[i] 지금까지 선택한 동전의 합이 i이기 위해 필요한 최소 동전개수 
// 합 i를 만들기 위해 마지막으로 사용한 동전이 j번째 동전(coin[j]) 인 경우


void InitDp(){
    for(int i=0; i<=m; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
}

int main() {

    cin >> n >> m;

    InitDp();

    for(int i=1; i<=n; i++)
        cin >> coin_category[i];


    for(int i=1; i<=m; i++){
        for(int j=1; j<=n;j++){
            if(i>=coin_category[j]){
                dp[i] = min(dp[i],dp[i-coin_category[j]]+1);
            }
        }
    }
    
    int ans = dp[m];

    if(ans == INT_MAX)
        ans = -1;
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}