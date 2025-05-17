#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100005

int n,m;
vector<int> p2c[MAX_N];
int dp[MAX_N];

void WriteDp(int p){
    for(int i=0; i<(int) p2c[p].size(); i++){
        int c = p2c[p][i];
        dp[c] += dp[p];
        WriteDp(c);
    }
    return;
}

int main() {
    
    cin >> n >> m;

    for(int c=1; c<=n; c++){
        int p;
        cin >> p;
        if(p == -1)
            continue;
        p2c[p].push_back(c);
    }

    for(int j=0; j<m; j++){
        int i,w;
        cin >> i >> w;
        dp[i] = w;
    }

    WriteDp(1);

    for(int i=1; i<=n; i++)
        cout << dp[i] <<" ";

    return 0;
}