#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 100001

vector<int> edges[MAX_N];
queue<int> q;
int indegree[MAX_N];
int n,m;

int main() {
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        edges[x].push_back(y);
        indegree[y]++;
    }
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;

    while(q.empty() == false){
        int x = q.front();
        q.pop();
        cnt++;
        int num = (int) edges[x].size();
        for(int i=0; i<num; i++){
            int y = edges[x][i];
            indegree[y]--;
            if(indegree[y] == 0)
                q.push(y);
        }
    }
    if(cnt == n)
        cout << "Consistent";
    else
        cout << "Inconsistent";

    return 0;
}