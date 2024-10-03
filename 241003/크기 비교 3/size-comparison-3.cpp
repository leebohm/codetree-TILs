#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 32001

vector<int> edges[MAX_N];
priority_queue<int> pq;
int indegree[MAX_N];
int n,m;

int main() {

    cin >>  n >> m;

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        indegree[y]++;
    }        

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            pq.push(-i);
    }

    while(pq.empty() == false){
        int x = pq.top();
        x = -x;
        pq.pop();
        cout << x <<" ";
        int num = (int) edges[x].size();
        for(int i=0; i<num; i++){
            int y = edges[x][i];
            indegree[y]--;
            if(indegree[y] == 0)
                pq.push(-y);
        }
    }

    return 0;
}