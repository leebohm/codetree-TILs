#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
vector<pair<int,int>> edge[MAX_N+1];
bool visited[MAX_N+1];
int dist[MAX_N+1];
int max_dist;
int last_node;
int a,b;
int ans;

void DFS(int x, int ignore_num){

    for(int i=0; i<edge[x].size(); i++){
        int y, dis;
        tie(y,dis) = edge[x][i];
        if(visited[y]) continue;
        visited[y] = true;
        dist[y] = dist[x] + dis;

        if(dist[y] > max_dist && y != ignore_num){
            max_dist = dist[y];
            last_node = y;
        }

        DFS(y, ignore_num);
    }
}

int main(){
    cin >> n;

    for(int i=1; i<=n-1; i++){
        int x, y, dis;

        cin >> x >> y >> dis;

        edge[x].push_back({y,dis});
        edge[y].push_back({x,dis});
    }

    visited[1] = true;
    DFS(1,-1);
    a = last_node;

    for(int i=1; i<=n; i++){
        visited[i] = false;
        dist[i] = 0;
    }

    max_dist = -1;
    visited[a] = true;
    DFS(a,-1);
    b = last_node;

    for(int i=1; i<=n; i++){
        visited[i] = false;
        dist[i] = 0;
    }

    max_dist = -1;
    visited[a] = true;
    DFS(a,b);
    ans = max(ans, max_dist);

    for(int i=1; i<=n; i++){
        visited[i] = false;
        dist[i] = 0;
    }

    max_dist = -1;
    visited[b] = true;
    DFS(b,a);
    ans = max(ans, max_dist);

    cout << ans;
    return 0;
}