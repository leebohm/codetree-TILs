#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 32001
int n,m;
vector<int> edges[MAX_N];
int indegree[MAX_N];
queue<int> q;

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }    

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(q.empty() == false){
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for(int i=0; i<(int) edges[x].size(); i++){
            int y = edges[x][i];
            indegree[y]--;
            if(indegree[y] == 0)
                q.push(y);
        }
    }
    
    return 0;
}