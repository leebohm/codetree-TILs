#include <iostream>
#define MAX_N 100001

using namespace std;

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
    if(rx != ry){
        uf[rx] = ry;
        sz[ry] += sz[rx];
    }
}

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        uf[i] = i;
        sz[i] = 1;
    }

    while(m--){
        char query;
        cin >> query;

        if(query == 'x'){
            int a,b;
            cin >> a >> b;
            Union(a,b);
        }

        else {
            int a;
            cin >> a;
            int ra = Find(a);
            cout << sz[ra] << endl;
        }
    }

    return 0;
}