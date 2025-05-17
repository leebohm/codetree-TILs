#include <iostream>
#include <memory.h>
#include <vector>
#include <climits>

using namespace std;

#define MAX_N 100005

int n,r;
vector<int> edges[MAX_N];
int mid_node = -1;
bool visited[MAX_N];
vector<int> p2c[MAX_N];
bool flag = false;
int dp[MAX_N];

void FindMid(int p){
    int child = (int) edges[p].size() - 1;

    if(p == r)
        child++;
    
    if(child >= 2 && mid_node == 0){
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

void MakeTree(int p){
    for(int i=0; i< (int) edges[p].size(); i++){
        int c = edges[p][i];
        if(visited[c] == false){
            visited[c] = true;
            p2c[p].push_back(c);
            MakeTree(c);
        }
    }
}

void WriteDp(int p){

    for(int i=0; i<(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        WriteDp(c);
    }

    if(dp[p] == 0)
        dp[p] = 1;

    for(int i=0; i<(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        dp[p] += dp[c];
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
    if(mid_node == -1)
        mid_node = r;

    memset(visited, false, sizeof(visited));
    visited[mid_node] = true;
    MakeTree(mid_node);
    WriteDp(mid_node);

    int min_num = INT_MAX;
    int max_num = INT_MIN;
    for(int i=0; i<(int)p2c[mid_node].size(); i++){
        int c = p2c[mid_node][i];
        min_num = min(min_num, dp[c]);
        max_num = max(max_num, dp[c]);
    }
    cout << abs(min_num - max_num);

    return 0;
}