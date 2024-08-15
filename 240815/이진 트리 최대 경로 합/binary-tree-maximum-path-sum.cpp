#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 30001

using namespace std;

int n;
vector<int> edges[MAX_N];
bool visited[MAX_N];
int dp[MAX_N];
int a[MAX_N];
int max_length[MAX_N];
int ans;

/*
1번 노드를 시작으로 DFS를 진행하며 값을 갱신한다 
dp[i] = i번 노드를 루트로 하는 서브트리에서
i번 노드를 끝으로 하는 경로 중 최대 합에서 해당하는 경로
max_length[i] = i번 노드를 루트로 하는 서브트리에서 두 자식노드로 이어지는 경로의 최댓값 
*/

void DFS(int x){
    vector<int> children;

    for(int i=0; i< (int)edges[x].size(); i++){
        int y = edges[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        DFS(y);
        children.push_back(y);
    } 
    int left = children.size() > 0 ? children[0] : 0;
    int right = children.size() > 1 ? children[1] : 0;

    dp[x] = a[x] + max(0, max(dp[left], dp[right]));

    max_length[x] = a[x] + max(0,dp[left])+max(0,dp[right]);
}

int main() {
    cin >> n;

    for(int i=1; i <=n-1; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    visited[1] = true;
    DFS(1);

    for(int i=1; i<=n; i++)
        ans = max(ans, max_length[i]);
    
    cout << ans;
    return 0;
}