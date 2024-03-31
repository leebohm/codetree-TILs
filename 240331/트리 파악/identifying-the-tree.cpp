#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

vector<int> edges[MAX_N+1];
vector<int> par[MAX_N+1];
bool visited[MAX_N+1];
int dist[MAX_N+1];
vector<int> leaves;
int n;

void DFS(int x, int d){
    
    for(int i=0; i<(int) edges[x].size(); i++){
        int y = edges[x][i];

        if(!visited[y]){
            visited[y] = true;
            dist[y] = d+1;
            par[x].push_back(y);
            DFS(y, d+1);
        }
    }
    return ;
}

int main() {

    cin >> n;

    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    visited[1] = true;
    DFS(1,0);

    for(int i=1; i<=n; i++){
        if((int) par[i].size() == 0)
            leaves.push_back(i);
    }

    int total_dist = 0;
    for(int i=0; i<(int)leaves.size(); i++){
        int tmp = leaves[i];
        total_dist+= dist[tmp];
    }

    if(total_dist % 2)
        cout << 1;
    else
        cout << 0;
    // 여기에 코드를 작성해주세요.
    return 0;
}