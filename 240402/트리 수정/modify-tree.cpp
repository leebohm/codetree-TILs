#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 2000

using namespace std;

int n;
vector<pair<int,int>> edge[MAX_N];
bool removed[MAX_N][MAX_N];
int edge_x[MAX_N], edge_y[MAX_N];
int edge_dist[MAX_N];

bool visited[MAX_N];
int dist[MAX_N];

int max_dist, last_node;
int ans;

void DFS(int x){
    for(int i=0; i<edge[x].size(); i++){
        int y,d;
        tie(y,d) = edge[x][i];

        if(removed[x][y]) continue;

        if(visited[y]) continue;

        visited[y] = true;

        dist[y] = dist[x] + d;

        if(dist[y] > max_dist){
            max_dist = dist[y];
            last_node = y;
        }

        DFS(y);
    }
}

void Init(){
    for(int i=0; i<n; i++) visited[i] = false;
    for(int i=0; i<n; i++) dist[i] = 0;
    max_dist = 0;

}

int GetTreeDiameter(int x){

    Init();
    last_node = x;

    visited[x] = true;
    DFS(x);

    Init();

    visited[last_node] = true;
    DFS(last_node);

    return max_dist;
}

int main(){

    cin >> n;

    for(int i=0; i<n-1; i++){
        int x, y, d;
        cin >> x >> y >> d;

        edge_x[i] = x;
        edge_y[i] = y;
        edge_dist[i] = d;
        edge[x].push_back(make_pair(y,d));
        edge[y].push_back(make_pair(x,d));
    }

    for(int i=0; i<n-1; i++){
        removed[edge_x[i]][edge_y[i]] = true;
        removed[edge_y[i]][edge_x[i]] = true;

        int max_diameter = edge_dist[i] + GetTreeDiameter(edge_x[i]) + GetTreeDiameter(edge_y[i]);
        ans = max(ans, max_diameter);

        removed[edge_x[i]][edge_y[i]] = false;
        removed[edge_y[i]][edge_x[i]] = false;
        
    }

    cout << ans;
    return 0;
}