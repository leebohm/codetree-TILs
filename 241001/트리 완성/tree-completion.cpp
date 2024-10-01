#include <iostream>
using namespace std;

#define MAX_N 100001

int n,m;
int uf[MAX_N];

int Find(int x){
    if(uf[x] == x)
        return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y){
    int rx = Find(x);
    int ry = Find(y);
    uf[rx] = ry;
}

int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        uf[i] = i;
    }
    int ans = 0;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        if(Find(a) == Find(b)){
            ans++;
            continue;
        }
        Union(a,b);
    }

    for(int i=2; i<=n; i++){
        if(Find(1) != Find(i)){
            Union(1,i);
            ans++;
        }
    }

    cout << ans;

    return 0;
}