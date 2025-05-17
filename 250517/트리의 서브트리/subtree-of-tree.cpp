#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100005

int n,r,q;
int dp[MAX_N];
vector<int> edges[MAX_N];
vector<int> p2c[MAX_N];
bool visited[MAX_N];

void FindChild(int p){
    for(int i=0; i< (int)edges[p].size(); i++){
        int c = edges[p][i];
        if(visited[c] == false){
            visited[c] = true;
            p2c[p].push_back(c);
            FindChild(c);
        }
    }
    return;
}
void WriteDp(int p){
    for(int i=0; i <(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        WriteDp(c);
    }

    if(dp[p] == 0)
        dp[p] = 1;
    for(int i=0; i<(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        dp[p] += dp[c];
    }
    return;
}

int main() {
    
    cin >> n >> r >> q;

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    visited[r] = true;
    FindChild(r);
    
    WriteDp(r);
    for(int i=0; i<q; i++){
        int tmp;
        cin >> tmp;
        cout << dp[tmp] <<"\n";
    }
    
    return 0;
}