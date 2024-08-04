#include <iostream>
#include <vector>

#define MAX_N 100001
using namespace std;

int n;
vector<int> edges[MAX_N];
bool visited[MAX_N];
int parent[MAX_N];

int dp[MAX_N][2];
//dp[1][0] = dp[c1][1] + dp[c2][1];
//dp[1][1] = dp[c1][0] + dp[c2][0];

void DFS(int x){
    for(int i=0; i<(int) edges[x].size(); i++){
        int y = edges[x][i];
            if(visited[y] == false){
                visited[y] = true;
                parent[y] = x;
                //cout << y << " " <<  x << endl;
                DFS(y);
            }        
    }

    dp[x][0] = 0;
    dp[x][1] = 1;

    for(int i=0;i<(int)edges[x].size(); i++){
        int y = edges[x][i];
        if(parent[y]!=x)
            continue;
        dp[x][0] += dp[y][1];
        dp[x][1] += dp[y][0];
    }
}

int main(){

    cin >> n;

    for(int i=1; i<=n-1; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    visited[1] = true;
    DFS(1);
    cout << min(dp[1][0],dp[1][1]);
    return 0;
}