#include <iostream>
using namespace std;

#define MAX_N 1001

int n,m;
int a,b;
int graph[MAX_N][MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

int main() {
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x,y,d;
        cin >> x >> y >> d;
        if(graph[x][y] == 0){
            graph[x][y] = d;
            graph[y][x] = d;
        }
        else{
            graph[x][y] = min(graph[x][y], d);
            graph[y][x] = min(graph[y][x], d);
        }
    }

    cin >> a >> b;

    for(int i=1; i<=n; i++)
        dist[i] = (int) 1e9;
    
    dist[b] = 0;

    for(int i=1; i<=n; i++){
        int min_idx = -1;
        for(int j=1; j<=n; j++){
            if(visited[j] == true)
                continue;
            if(min_idx == -1 || dist[min_idx] > dist[j])
                min_idx = j;            
        }
        visited[min_idx] = true;

        for(int j=1; j<=n; j++){
            if(graph[min_idx][j] == 0)
                continue;
            if(dist[j] > dist[min_idx] + graph[min_idx][j])
                dist[j] = dist[min_idx] + graph[min_idx][j];
        }
    }
    cout << dist[a] << "\n";
    return 0;
}