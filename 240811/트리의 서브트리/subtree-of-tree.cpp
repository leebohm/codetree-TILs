#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100001

int n,r,q; // n : 트리의 정점의 수, r : 루트의 번호, q : 조사할 정점의 수 

vector<int> tree[MAX_N];
int parents[MAX_N];
bool visited[MAX_N];
int treeDP[MAX_N]; // index : 근데 그러면 맨 끝에 자식노드 부터 시작해야하는 것 아닌가..? 

void DFS(int idx){

    int num = tree[idx].size();
    treeDP[idx] = 1;

    for(int i = 0; i < num ; i++){
        int tmp = tree[idx][i];
        if(visited[tmp] == false){
            parents[tmp] = idx;
            visited[tmp] = true;
            DFS(tmp);
            treeDP[idx]+=treeDP[tmp];
        }
    }
}

int main() {
    cin >> n >> r >> q;

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visited[r] = true;
    DFS(r);

    for(int i=0; i<q;i++){
        int u;
        cin >> u;
        cout << treeDP[u] << endl;
    }

    return 0;
}