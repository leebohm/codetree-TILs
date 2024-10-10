#include <iostream>

using namespace std;

#define MAX_N 1001

int n,m,a,b;
int graph[MAX_N][MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

int main(){

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y,d;
        cin >> x >> y >> d;
        graph[x][y] = d;
        graph[y][x] = d;
    }

    for(int i=1; i<=n; i++)
        dist[i] = (int) 1e9;

    cin >> a >> b;
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

    cout << dist[a] << endl;

    int x = a;
    cout << x <<" ";
    while( x!= b){
        for(int i=1; i<=n; i++){
            if(graph[i][x] == 0)
                continue;
            if(dist[x] == graph[i][x] + dist[i]){
                x = i;
                break;
            }
        }
        cout << x << " ";
    }
    return 0;
}