#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100001

int n,m; // 노드의 수 : n, 초기 연산의 수 : m
int parents[MAX_N];
vector<int> children[MAX_N];
int score[MAX_N];
bool visited[MAX_N];

void DFS(int idx){

    int num = children[idx].size();
    for(int i=0; i<num; i++){
        int tmp = children[idx][i];
        if(visited[tmp] == false){
            score[tmp] += score[idx];
            visited[tmp] = true;
            //cout << tmp << " " << score[tmp] << " " << score[idx] << endl;
            DFS(tmp);
            //score[tmp] += score[idx];
        }
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
        score[idx] += w;
    }

    visited[1] = true;
    DFS(1);

    for(int i=1; i<=n; i++){
        cout << score[i] << " ";
    }

    return 0;
}