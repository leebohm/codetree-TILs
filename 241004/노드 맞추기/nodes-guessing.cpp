#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int n,m;

map<string, int> string_to_node;
string nodes[MAX_N];

vector<int> edges[MAX_N];
vector<int> root;
vector<int> child[MAX_N];

int indegree[MAX_N];

queue<int> q;

int main(){
    
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> nodes[i];
    
    sort(nodes+1, nodes+n+1);

    for(int i=1; i<=n; i++)
        string_to_node[nodes[i]]= i;
    
    cin >> m;

    for(int i=1; i<=m; i++){
        string x_str, y_str;
        cin >> x_str >> y_str;

        int x,y;
        x = string_to_node[x_str];
        y = string_to_node[y_str];

        edges[y].push_back(x);
        indegree[x]++;
    }

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            root.push_back(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<(int) edges[x].size(); i++){
            int y = edges[x][i];
            indegree[y]--;

            if(!indegree[y]){
                q.push(y);

                child[x].push_back(y);
            }
        }
    }

    for(int i=1; i<=n; i++)
        sort(child[i].begin(), child[i].end());
    
    cout << root.size() << endl;
    for(int i=0; i<root.size(); i++)
        cout << nodes[root[i]] << " ";
    
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << nodes[i] << " ";
        cout << (int) child[i].size() << " ";

        for(int j=0; j<child[i].size(); j++){
            int x = child[i][j];
            cout << nodes[x] << " ";
        }
        cout << endl;
    }
    return 0;
}