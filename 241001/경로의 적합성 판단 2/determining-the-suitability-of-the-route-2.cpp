#include <iostream>
using namespace std;

#define MAX_N 100001

int n,m; // n 개의 정점, m 개의 간선으로 이루어진 양방향 그래프 
int k;
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
    
    cin >> n >> m >> k;

    for(int i=1; i<=n;i++)
        uf[i] = i;

    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        Union(x,y);
    }

    int p;
    cin >> p;
    int rp = Find(p);
    bool flag = true;
    for(int i=0; i<k; i++){
        cin >> p;
        if(Find(p) != rp){
            cout << 0;
            flag = false;
            break;
        }

    }
    if(flag == true)
        cout << 1;

    return 0;
}