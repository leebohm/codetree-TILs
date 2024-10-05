#include <iostream>

using namespace std;

#define MAX_N 100001

int n,m,k;

int uf[MAX_N];

int Find(int x){
    if(uf[x] == x)
        return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y){
    int rx = uf[x];
    int ry = uf[y];
    uf[rx] = ry;
}

int main(){
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++)
        uf[i] = i;
    
    for(int i=0;i<m; i++){
        int x,y;
        cin >> x >> y;
        Union(x,y);
    }
    int idx;
    cin >> idx;
    int last_val = Find(idx);
    bool flag = true;
    for(int i=0; i<k-1; i++){
        cin >> idx;
        if(last_val != Find(idx)){
            flag = false;
            break;
        }
    }

    if(flag == true)
        cout << 1;
    else
        cout << 0;

    return 0;
}