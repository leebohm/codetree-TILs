#include <iostream>
using namespace std;

#define MAX_N 100001

int n,m;
int uf[MAX_N];
int cnt[MAX_N];

int Find(int a){
    if(uf[a]==a)
        return a;
    int ra = Find(uf[a]);
    uf[a] = ra;
    cnt[ra]++;
    return uf[a];
}
void Union(int a, int b){
    int ra = Find(a);
    int rb = Find(b);
    uf[ra] = rb;
    cnt[rb]++;
}
int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        uf[i] = i;
    }

    for(int i=0; i<m; i++){
        char c;
        int a,b;
        cin >> c ;
        if(c == 'x'){
            cin >> a >> b;
            Union(a,b);
        }
        else if(c == 'y'){
            cin >> a;
            int tmp = Find(a);

            if(cnt[tmp]==0)
                cout << 1 << endl;
            else
                cout << cnt[tmp] << endl;
        }
    }
        
    return 0;
}