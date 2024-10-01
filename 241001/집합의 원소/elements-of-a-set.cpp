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
    
    while(m--){
        int q_type, a, b;
        cin >> q_type >> a >> b;

        if(q_type == 0)
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