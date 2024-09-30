#include <iostream>
using namespace std;

#define MAX_N 100001

int n,q;
int idxs[MAX_N];
int L[MAX_N];
int R[MAX_N];

int main() {
    
    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> idxs[i];
    }

    L[0] = idxs[0];
    R[n-1] = idxs[n-1];

    for(int i=1; i<n; i++)
        L[i] = max(L[i-1], idxs[i]);
    
    for(int i=n-2; i >=0; i--)
        R[i] = max(R[i+1], idxs[i]);
    
    int x,y;
    for(int i=0; i<q; i++){
        cin >> x >> y;
        x--; y--;
        int ans = max(L[x-1], R[y+1]);
        cout << ans << endl;
    }
    return 0;
}