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

int main(){

    cin >> n >> m;

    for(int i=1; i<=n;i++)
        uf[i] = i;
    
    for(int i=0; i<m; i++){
        int opt, a,b;
        cin >> opt >> a >> b;
        if(opt == 0)
            Union(a,b);
        else{
            if(Find(a) == Find(b))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
            
    }

    return 0;
}