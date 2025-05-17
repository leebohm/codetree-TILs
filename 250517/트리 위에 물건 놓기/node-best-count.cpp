#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100005
int n;
vector<int> edges[MAX_N];
bool visited[MAX_N];
vector<int> p2c[MAX_N];
int dp[MAX_N][2]; //dp[i][0] : i번 노드에 물건 없음, dp[i][1] : i번 노드에 물건 있음

void FindChildren(int p){
    for(int i=0; i<(int) edges[p].size(); i++){
        int c = edges[p][i];
        if(visited[c] == false){
            visited[c] = true;
            p2c[p].push_back(c);
            FindChildren(c);
        }
    }
    return;
}

void Count(int p){
    for(int i=0; i<(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        Count(c);
    } 

    if(dp[p][1] == 0)
        dp[p][1] = 1;

    for(int i=0; i<(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        dp[p][0] += dp[c][1];
        dp[p][1] += dp[c][0];
    }
    return;
}

int main() {

    cin >> n;
    
    for(int i=0; i<n-1 ; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);        
    }
    visited[1] = true;
    FindChildren(1);
    Count(1);
    

    cout << min(dp[1][0], dp[1][1]);
    
    return 0;
}