#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int n,m;
int parts;

vector<int> edges[MAX_N];
int indegree[MAX_N];
bool visited[MAX_N];

queue<int> q;
vector<int> ans;
int main(){
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a,k;
        cin >> a >> k;

        while(k--){
            int x;
            cin >> x;
            edges[x].push_back(a);
            indegree[a]++;
        }
    }
    cin >> parts;
    for(int i=1; i<=parts;i++){
        int x;
        cin >> x;
        q.push(x);
        visited[x] = true;
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        ans.push_back(x);

        for(int i=0; i<(int) edges[x].size(); i++){
            int y = edges[x][i];
            if(visited[y])
                continue;

            indegree[y]--;

            if(!indegree[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i=0; i<(int) ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}