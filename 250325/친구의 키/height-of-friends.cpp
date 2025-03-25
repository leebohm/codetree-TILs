#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n,m;
#define MAX_N 100005
vector<int> edges[MAX_N];
bool visited[MAX_N];
stack <int> order;
void DFS(int x){
    if(edges[x].size() == 0)
        return;

    for(int i=0; i<edges[x].size(); i++){
        int y = edges[x][i];
        if(visisted[y] == false)
            DFS(y);
    }

    order.push_back(x);
}
int main() {
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == false)
            DFS(i);
    }

    while(stack.empty() == false){
        int x = stack.top();
        stack.pop();
        cout << x <<" ";
    }
    return 0;
}


// 키가 큰 순서대로 서있다. 