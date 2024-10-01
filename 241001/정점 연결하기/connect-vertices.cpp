#include <iostream>

#define MAX_N 100000

using namespace std;

int n;

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
    cin >> n;

    for(int i=1; i<=n; i++)
        uf[i] = i;

    for(int i=1; i<=n-2; i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    for(int i=2; i<=n; i++){
        int ri = Find(i);
        if(ri != Find(1)){
            cout << 1 << " " << i;
            break;
        }
    }

    return 0;
}