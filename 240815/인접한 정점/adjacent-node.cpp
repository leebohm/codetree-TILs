#include <iostream>
#include <vector>

#define MAX_N 10001

using namespace std;

int n;
vector<int> edges[MAX_N];
bool visited[MAX_N];
int a[MAX_N];
int dp[MAX_N][2];

void DFS(int x){
    
    dp[x][1] = a[x];

    for(int i=0; i<(int) edges[x].size(); i++){
        int y = edges[x][i];

        if(visited[y]) continue;

        visited[y] = true;
        DFS(y);

        dp[x][1] += dp[y][0];
        dp[x][0] += max(dp[y][0], dp[y][1]);
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    for(int i=1; i<=n-1; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[1] = true;
    DFS(1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}