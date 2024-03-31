#include <iostream>
#include <vector>

#define MAX_N 10001

using namespace std;

vector<int> edges[MAX_N];
int m;
int comein[MAX_N];
int ans = 0;
bool visited[MAX_N];

void DFS(int x){
    
    for(int i=0; i<(int)edges[x].size(); i++){
        int y = edges[x][i];
        
        if(!visited[y]){
            ans++;
            DFS(y);
        }

    }
}

int main() {

    int x, y;
    cin >> m;
    
    int max_node = 0;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        max_node = max(max_node,max(x,y));
        comein[y]++;
        edges[x].push_back(y);
    }

    int root = 0;

    for(int i=1; i<= max_node ;i++ ){
        if((int) edges[i].size() > 0 && comein[i] == 0)
            root = i;
    }

    visited[root] = true;
    DFS(root);

    if(ans == m)
        cout << 1;
    else
        cout << 0;

    // 여기에 코드를 작성해주세요.
    return 0;
}