#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 10001

using namespace std;

int n;
int a[MAX_N];
vector<int> edges[MAX_N];
bool visited[MAX_N];

int dp[MAX_N]; 
// dp[i] : i를 루트로 하는 서브트리를 전부 처리했을 때 최종적으로 i가 가지게 되는 값
// 서브트리를 전부 처리했다는 말의 의미가 뭐지..?

int ans;

// DFS를 통해 연결된 모든 정점을 순회한다. 
// 자식부터 그리디하게 1로 만들어주는게 최선
void DFS(int x){
    // dp 값은 주어진 초기값이 된다. 
    dp[x] = a[x];

    for(int i=0; i<(int) edges[x].size(); i++){
        int y = edges[x][i];

        if(visited[y] == true)
            continue;
        
        visited[y] = true;
        DFS(y);

        // 자식들의 값들 전부 더해준다. 
        // 이때 자식들은 1만 남기고 가져와준다. 
        dp[x] += dp[y] - 1;
    }

    // dp[x]를 1로 만들기 위해 필요한 비용을 계산한다 
    ans += abs(dp[x] - 1);
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[1] = true;
    DFS(1);

    cout << ans;
    return 0;
}