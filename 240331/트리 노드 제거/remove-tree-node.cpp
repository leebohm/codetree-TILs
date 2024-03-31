#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50

using namespace std;

int n;
int ans;
int root;
int par[MAX_N];
vector<int> edges[MAX_N];
bool is_deleted[MAX_N];

void DFS(int x){
    if(is_deleted[x])
        return ;
    
    bool is_leaf = true;

    for(int i=0; i<edges[x].size(); i++){
        int y = edges[x][i];

        if(is_deleted[y])
            continue;
        DFS(y);
        is_leaf = false;
    }

    if(is_leaf)
        ans ++;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> par[i];
        x = i;
        y = par[i];

        if(y== -1){
            root = x;
            continue;
        }

        edges[y].push_back(x);
    }

    int del_node;
    cin >> del_node;

    is_deleted[del_node] = true;

    DFS(root);

    cout << ans;
    return 0;
}