#include <iostream>

using namespace std;

#define MAX_N 100001

int n,m;
int uf[MAX_N];
int sz[MAX_N];

int Find(int x){
    if(uf[x] == x)
        return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y){
    int rx = Find(x);
    int ry = Find(y);
    uf[rx] = ry;
    if(rx != ry)
        sz[ry] += sz[rx];
}

int main(){

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        uf[i] = i;
        sz[i] = 1;
    }

    char c;
    for(int i=0; i<m; i++){
        cin >> c;
        if(c == 'x'){
            int a,b;
            cin >> a >> b;
            Union(a,b);
        }
        else{
            int a;
            cin >> a;
            int idx  = Find(a);
            cout << sz[idx] << endl;
        }
    }

    return 0;
}