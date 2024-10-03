#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100001

using namespace std;

int n,m;
vector<int> edges[MAX_N];

int indegree[MAX_N];

queue<int> q;

int main(){
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        indegree[y]++;
    }

    for(int i=1; i<=n; i++)
        if(indegree[i]==0)
            q.push(i);

    while(q.empty() == false){

        int x = q.front();
        q.pop();

        cout << x << " ";

        for(int i=0; i<(int) edges[x].size(); i++){
            int y = edges[x][i];

            indegree[y]--;

            if(!indegree[y])
                q.push(y);
        }
    }
    return 0;
}