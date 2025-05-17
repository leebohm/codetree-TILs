#include <iostream>
#include <memory.h>
#include <vector>
#include <climits>

using namespace std;

#define MAX_N 100005

int n,r;
vector<int> edges[MAX_N];
int mid_node;
bool visited[MAX_N];
bool flag = false;
int dp[MAX_N];

void FindMid(int p){
    int child = (int) edges[p].size() - 1;

    if(p == r)
        child++;
    
    if(child >= 2 && mid_node == 0){
        mid_node = p;
    }

    if(child == 0 && mid_node == 0){
        mid_node = p;
    }
    
    for(int i=0; i < (int) edges[p].size(); i++){
        int c = edges[p][i];
        if(visited[c])
            continue;
        visited[c] = true;
        FindMid(c);
    }
    return;
}

// DFS를 통해 각 노드를 루트로 하는 서브트리의 노드의 개수를 계산합니다.
void DFS(int x) {
    dp[x] = 1;

    for(int i = 0; i < edges[x].size(); i++) {
        int y = edges[x][i];

        // 이미 방문한 노드는 스킵합니다.
        if(visited[y]) 
            continue;

        visited[y] = true;
        DFS(y);

        dp[x] += dp[y];
    }
}

int main() {
    
    cin >> n >> r;

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[r] = true;
    FindMid(r);

    memset(visited, false, sizeof(visited));

    visited[mid_node] = true;
    DFS(mid_node);

    int min_num = INT_MAX;
    int max_num = INT_MIN;
    for(int i=0; i<(int)edges[mid_node].size(); i++){
        int c = edges[mid_node][i];
        min_num = min(min_num, dp[c]);
        max_num = max(max_num, dp[c]);
    }
    cout << max_num - min_num;

    return 0;
}