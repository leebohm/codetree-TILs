#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 32001

using namespace std;

int n,m;
vector<int> edges[MAX_N];
int indegree[MAX_N];

priority_queue<int> pq;

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        indegree[y]++;
    }

    for(int i=1; i<=n; i++)
        if(!indegree[i])
            pq.push(-i);
    
    while(!pq.empty()){
        int x = -pq.top();
        pq.pop();
        cout <<  x <<" ";

        for(int i=0; i<(int) edges[x].size(); i++){
            int y = edges[x][i];
            indegree[y]--;

            if(!indegree[y])
                pq.push(-y);
        }
    }
    return 0;
}