#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 10000

using namespace std;

int m;
int root;
int deg[MAX_N+1];
vector<int> edges[MAX_N+1];
bool used[MAX_N+1];
bool visited[MAX_N+1];
bool is_tree = true;

void DFS(int x){
    for(int i=0; i<edges[x].size(); i++){
        int y = edges[x][i];
        
        if(visited[y])
            continue;
        
        visited[y] = true;
        DFS(y);
    }
    return;
}

int main(){
    cin >> m;
    for(int i=1; i<=m; i++){
        int x, int y;
        cin >> x >> y;

        edges[x].push_back(y);
        used[x] = used[y] = true;

        deg[y]++;
    }

    for(int i=1; i<=MAX_N; i++){
        if(used[i] && deg[i] == 0){
            if(root != 0)
                is_tree = false;
            root = i;
        }
    }

    if(root == 0)
        is_tree = false;
    
    for(int i=1; i<=MAX_N; i++){
        if(used[i] && i != root && deg[i] != 1)
            is_tree = false;
    }

    if(is_tree){
        visited[root] = true;
        DFS(root);
    }

    for(int i-1; i<=MAX_N; i++){
        if(used[i] && !visited[i] )
            is_tree = false;
    }

    if(is_tree) cout << 1;
    else cout << 0;
    return 0;
}