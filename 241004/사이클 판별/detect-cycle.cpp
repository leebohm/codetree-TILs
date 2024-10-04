#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100001
int n,m;
vector<int> edges[MAX_N];
int indegree[MAX_N];
bool visited[MAX_N];
queue<int> q;

int main() {

    cin >> n >> m;

    int a,b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }

    }

    while(q.empty() == false){
        int x = q.front(); q.pop();
        for(int i=0; i<(int) edges[x].size(); i++){
            int y = edges[x][i];
            indegree[y]--;
            if(indegree[y] == 0){
                if(visited[y] == true){
                    cout << "Exists" ;
                    return 0;
                }
                q.push(y);
                visited[y] = true;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == false){
            cout << "Exists";
            return 0;
        }
    }
    cout << "Not Exists";
    return 0;
}