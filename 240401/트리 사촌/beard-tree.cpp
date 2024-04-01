#include <iostream>
#include <vector>
#define MAX_N 1000

using namespace std;

int n,k;
int a[MAX_N+1];
int par[MAX_N+1];
int finding_node;
int ans;

int main(){
    cin >> n >>k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] == k)
            finding_node = i;
    }

    int par_node = 0;
    
    for(int i=2; i<=n; i++){

        if(a[i] > a[i-1] +1)
            par_node++;

        par[i] = par_node;
    }

    for(int i=1; i<=n; i++){
        if(!par[par[i]] || ! par[par[finding_node]])
            continue;
        
        if(par[i] != par[finding_node] && par[par[i]] == par[par[finding_node]])
            ans++;
    }

    cout << ans;
    return 0;
    
}