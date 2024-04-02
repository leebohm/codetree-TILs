#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50001

using namespace std;

int n,d;
vector<pair<int,int>> edge[MAX_N];
bool used[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

void DFS(int x){
    for(int i=0; i<edge[x].size(); i++){
        int y,tmp;
        tie(y,tmp) = edge[x][i];
        if(!visited[y]){
            dist[y] = dist[x] + tmp;
            visited[y] = true;
            DFS(y);
        }
    }
}

void Initialize(){
    for(int i= 0; i< MAX_N; i++){
        dist[i] = 0;
        visited[i] = false;
    }
}

pair<int,int> FindMax(){
    int d_  = 0;
    int idx = 0;
    for(int i=0; i<MAX_N; i++){
        if(used[i]){
            if(d_ < dist[i]){
                d_ = dist[i];
                idx = i;
            }
        }
    }
    Initialize();
    return make_pair(idx, d_);
}

int main() {

    cin >> n >> d;

    int root = 0;
    for(int i=0; i<n-1; i++){
        int x,y,dist;
        cin >> x >> y >> dist;

        edge[x].push_back(make_pair(y,dist));
        edge[y].push_back(make_pair(x,dist));
        used[x] = used[y] = true;
        root = x;
        
    }

    visited[root] = true;
    DFS(root);

    int f_vertex, f_dist;
    tie(f_vertex,f_dist) = FindMax();

    visited[f_vertex] = true;
    DFS(f_vertex);

    tie(f_vertex,f_dist) = FindMax();

    if(f_dist/d)
        cout << f_dist / d + 1;
    else
        cout << f_dist / d;
    // 여기에 코드를 작성해주세요.
    return 0;
}