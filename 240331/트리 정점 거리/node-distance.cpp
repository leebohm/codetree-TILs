#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 1000

using namespace std;

int n,m;
vector<pair<int,int>> edges[MAX_N+1];
bool visited[MAX_N+1];
int dist[MAX_N+1][MAX_N+1];

void DFS(int st, int x){
    for(int i =0; i<(int) edges[x].size(); i++){
        int y,d;
        tie(y,d) = edges[x][i];

        if(visited[y]) continue;

        visited[y] = true;
        dist[st][y] = dist[st][x] +d;
        DFS(st,y);
    }
}

int main(){

    cin >> n >> m;
    for(int i=1; i<=n-1; i++){
        int x,y,d;
        cin >> x >> y >> d;

        edges[x].push_back({y,d});
        edges[y].push_back({x,d});

    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            visited[j] = false;

        visited[i] = true;
        DFS(i,i);
    }


    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
    return 0;
}