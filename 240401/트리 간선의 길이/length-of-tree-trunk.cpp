#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 10001

using namespace std;

vector<pair<int,int>> edges[MAX_N];
int n =  0;
bool visited[MAX_N];
int dist[MAX_N];

void DFS(int x, int total_dist){
    for(int i=0; i<(int) edges[x].size(); i++){
        int y,d;
        tie(y,d) = edges[x][i];
        if(!visited[y]){
            dist[y] = dist[x] + d;
            visited[y] = true;
            DFS(y, total_dist+d);
        }
    }
    return;
}

void Initialize(){
    for(int i=0; i<MAX_N; i++){
        dist[i] = 0;
        visited[i] = false;
    }
}

pair<int,int> FindVertex(){
    int d = 0;
    int vertex = 0;
    for(int i=1; i<=n; i++){
        if(d < dist[i]){
            d = dist[i];
            vertex = i;
        }
    }

    Initialize();

    return make_pair(vertex,d);
}


int main() {
    
    cin >> n;

    int root = 0;

    for(int i=0; i<n; i++){
        int x, y,d;
        cin >> x >> y >> d;
        edges[x].push_back(make_pair(y,d));
        edges[y].push_back(make_pair(x,d));
        root = x;
    }

    visited[root];
    DFS(root,0);

    int f_vertex;
    int dist;
    tie(f_vertex,dist) = FindVertex();

    visited[f_vertex] = true;

    DFS(f_vertex,0);

    tie(f_vertex, dist) = FindVertex();

    
    cout << dist;


    // 여기에 코드를 작성해주세요.
    return 0;
}