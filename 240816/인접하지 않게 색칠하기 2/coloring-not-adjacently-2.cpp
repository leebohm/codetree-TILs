#include <iostream>
#include <vector>

#define MAX_N 100001
#define MAX_K 11

using namespace std;

int n,k;
vector<int> edges[MAX_N];
bool visited[MAX_N];
int a[MAX_N];
int dp[MAX_N][MAX_K][2];
int ans;

void DFS(int x){
    int left_num = 0;
    int right_num = 0;

    for(int i=0; i<(int) edges[x].size(); i++){
        int y = edges[x][i];

        if(visited[y])
            continue;
        
        visited[y] = true;
        DFS(y);

        if(left_num == 0)
            left_num = y;
        else 
            right_num = y;
    }

    dp[x][1][1] = a[x];
    dp[x][0][0] = 0;

    if(left_num && right_num) {
        for(int i=1; i<=k; i++)
            for(int j=1; j<=i; j++)
                dp[x][i][1] = max(dp[x][i][1], dp[left_num][j][0] + dp[right_num][i-j-1][0] + a[x]);

            for(int i=0; i<=k; i++)
                for(int j=0; j<=i; j++)
                    dp[x][i][0] = max(dp[x][i][0],
                                    max(dp[left_num][j][0], dp[left_num][j][1]) +
                                    max(dp[right_num][i-j][0], dp[right_num][i-j][1]));
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n-1; i++){
        int x,y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    cin >> k;

    visited[1] = true;
    DFS(1);

    for(int i=1; i<=k; i++){
        ans = max(ans, dp[1][i][0]);
        ans = max(ans, dp[1][i][1]);
    }

    cout << ans;
    return 0;
}