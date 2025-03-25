#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 32005

int n,m;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> edges[MAX_N];
int indegree[MAX_N];

int main() {
    
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            pq.push(i);
    }

    while(pq.empty() == 0){
        int x = pq.top();
        pq.pop();
        cout << x <<" ";
        for(int i=0; i<edges[x].size(); i++){
            int y = edges[x][i];
            indegree[y]--;
            if(indegree[y] == 0)
                pq.push(y);
        }
    }

    return 0;
}