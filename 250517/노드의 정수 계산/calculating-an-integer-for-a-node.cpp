#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100005

int n;
int val[MAX_N];
int dp[MAX_N];
vector<int> edges[MAX_N];

void DFS(int p){
    for(int i=0; i < (int) edges[p].size(); i++){
        int c = edges[p][i];
        DFS(c);
    }

    dp[p] = val[p];
    for(int i=0; i<(int) edges[p].size(); i++){
        int c = edges[p][i];
        if(dp[c] > 0)
            dp[p] += dp[c];
    }
    return;
}

int main() {
    
    cin >> n;
    for(int i=2; i<=n; i++){
        int t,a,p;
        cin >> t >> a >> p;
        edges[p].push_back(i);
        val[i] = (t == 1) ? a : -1*a;
    }

    DFS(1);

    cout << dp[1];

    return 0;
}