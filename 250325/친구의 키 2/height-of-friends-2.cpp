#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100005

int n,m;
int indegree[MAX_N];
vector<int> edges[MAX_N];
queue<int> q;

int main() {
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i]== 0)
            q.push(i);
    }

    int cnt = 0;
    while(q.empty() == false){
        int x = q.front();
        q.pop();
        cnt++;
        for(int i=0; i<edges[x].size(); i++){
            int y = edges[x][i];
            indegree[y]--;
            if(indegree[y] == 0)
                q.push(y);
        }
    }
    if(cnt == n)
        cout <<"Consistent";
    else
        cout << "Inconsistent";
    return 0;
}