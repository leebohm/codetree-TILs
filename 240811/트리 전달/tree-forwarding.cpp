#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100001

int n,m; // 노드의 수 : n, 초기 연산의 수 : m
int parents[MAX_N];
vector<int> children[MAX_N];
int score[MAX_N];

void DFS(int idx, int w){

    int num = children[idx].size();
    score[idx] += w;
    for(int i=0; i<num; i++){
        int tmp = children[idx][i];
        DFS(tmp,w);
    }
}

int main() {

    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        cin >> parents[i];
        children[parents[i]].push_back(i);
    }

    for(int i=1; i<=m; i++){
        int idx, w;
        cin >> idx >> w;
        DFS(idx,w);
    }
    for(int i=1; i<=n; i++){
        cout << score[i] << " ";
    }

    return 0;
}