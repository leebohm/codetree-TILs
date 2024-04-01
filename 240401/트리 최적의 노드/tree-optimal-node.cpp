#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 100001
using namespace std;

int n;
vector<int> edges[MAX_N];
bool used[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

void DFS(int x){

    for(int i=0; i<edges[x].size(); i++){
        int y = edges[x][i];
        if(!visited[y]){
            visited[y] = true;
            dist[y] = dist[x] + 1;
            DFS(y);
        }
    }
    return;
}

void Initialize(){
    for(int i=0; i<MAX_N; i++){
        visited[i] = false;
        dist[i] = 0;
    }
}
int FindMaxDist(){
    int d = INT_MIN;
    for(int i=0; i<MAX_N; i++){
        if(used[i]){
            d = max(d,dist[i]);
        }
    }
    return d;
}

int FindMinDist(){
    int d = INT_MAX;
    for(int i=0; i<MAX_N; i++){
        if(used[i]){
            Initialize();
            visited[i] = true;
            DFS(i);
            int tmp = FindMaxDist();
            if(tmp != 0)
                d = min(d, tmp);
        }
    }
    return d;
}

int main() {

    cin >> n;

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
        used[x] = used[y] = true;
    }

    int ans = FindMinDist();

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}