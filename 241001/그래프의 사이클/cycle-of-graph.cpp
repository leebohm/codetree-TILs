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

void PrintUF(){
    for(int i=1; i<=n; i++)
        cout << i << " ";
    cout << endl;
    for(int i=1; i<=n; i++)
        cout << uf[i] << " ";
    cout << endl;
    cout << endl;
}

int main() {
    
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        uf[i] = i;
    
    bool flag = true;

    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        if(Find(a) == Find(b)){
            cout << i << endl;
            flag = false;
            break;
        }
        Union(a,b);
    }

    if(flag == true)
        cout << "happy";

    return 0;
}