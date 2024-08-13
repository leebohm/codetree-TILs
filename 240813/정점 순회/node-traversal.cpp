#include <iostream>
#include <vector>

#define MAX_N 100001

using namespace std;

int n,s,d;
vector<int> edges[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];

int ans;

void DFS(int x){
    for(int i=0; i<(int) edges[x].size(); i++){
        int y = edges[x][i];

        if(visited[y])
            continue;
        
        visited[y] = true;
        DFS(y);

        dist[x] = max(dist[x],1+dist[y]);
    }
}
 
int main(){
    cin >> n >> s >> d;

    for(int i=1; i<=n-1; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[s] = true;
    DFS(s);

    for(int i=1; i<=n; i++){
        if(i==s) continue;
        if(dist[i] >= d)
            ans++; // 왜 d 이상일때마다 ++하냐면, 어차피 모든 정점을다 거쳐야함. 안 거치고 건너뛴다고 해도 +2 이기 때문 
    }
    cout << ans * 2; // 왜 2배하는지 알겟음 
    return 0;
}