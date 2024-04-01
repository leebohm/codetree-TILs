#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;
vector<int> edge[MAX_N+1];
bool visited[MAX_N+1];
int dist[MAX_N+1];
int max_dist;
int last_node;

void DFS(int x){

    visited[x] = true;

    for(int i=0; i<edge[x].size(); i++){
        int y = edge[x][i];

        if(visited[y]) continue;

        dist[y] = dist[x] + 1;

        if(dist[y] > max_dist){
            max_dist = dist[y];
            last_node = y;
        }

        DFS(y);
    }
}

int main(){

    cin >> n;

    for(int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;

        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    DFS(1);

    for(int i=1; i<=n; i++){
        visited[i] = false;
        dist[i] = 0;
    }

    DFS(last_node);

    cout << (max_dist + 1) / 2;
    return 0;
}