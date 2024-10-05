#include <iostream>

#define MAX_N 100001

using namespace std;

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

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        uf[i] = i;
    
    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        if(Find(a) == Find(b)){
            cout << i ;
            return 0;
        }
        Union(a,b);
    }
    cout << "happy";
    return 0;
}