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

    for(int i=0; i<edges[x].size(); i++){
        int y = edges[x][i];
        if(visited[y] == false){
            visited[y] = true;
            DFS(y);
        }
    }

    order.push(x);
}
int main() {
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == false){
            visited[i] = true;
            DFS(i);
        }
    }

    while(order.empty() == false){
        int x = order.top();
        order.pop();
        cout << x <<" ";
    }
    return 0;
}


// 키가 큰 순서대로 서있다. 