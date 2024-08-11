#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define MAX_N 100001

int n,r;
vector<int> tree[MAX_N];
int parents[MAX_N];
int central_node = 0;
bool flag = false;
int treeDP[MAX_N];
bool visited[MAX_N];
vector<int> children[MAX_N];

void DFS2(int idx){

    int num = children[idx].size();
    if(num >= 2 && flag == false){
        central_node = idx;
        flag = true;
    }
    treeDP[idx] = 1;
    for(int i=0; i<num; i++){
        int tmp = children[idx][i];
        DFS2(tmp);
        treeDP[idx] += treeDP[tmp];
    }
}

void DFS(int idx){

    int num = tree[idx].size();
    for(int i=0; i<num; i++){
        int tmp = tree[idx][i];
        if(visited[tmp] == false){
            children[idx].push_back(tmp);
            visited[tmp] = true;
            DFS(tmp);   
        }
    }
}

int main() {

    cin >> n >> r;

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visited[r] = true;
    DFS(r);
    DFS2(r);

    int num = children[central_node].size();
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    for(int i=0; i<num; i++){
        int tmp = children[central_node][i];
        max_val = max(max_val, treeDP[tmp]);
        min_val = min(min_val, treeDP[tmp]);
    }
    if(max_val == INT_MIN || min_val == INT_MAX)
        cout << 0;
    else
        cout << abs(max_val-min_val);
    
    return 0;
}