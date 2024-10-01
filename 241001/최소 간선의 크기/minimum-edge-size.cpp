#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int n,m;
int a,b;

int uf[MAX_N+1];

vector<tuple<int, int, int> > edges;

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
    cin >> a >> b;

    for(int i=1; i<=n; i++)
        uf[i] = i;
    
    for(int i=1; i<=m; i++){
        int x, y, d;
        cin >> x >> y >> d;
        edges.push_back(make_tuple(-d,x,y));
    }

    sort(edges.begin(), edges.end());

    for(int i=0; i<m; i++){
        int d, x, y;
        tie(d,x,y) = edges[i];

        Union(x,y);
        if(Find(a) == Find(b)){
            cout << -d;
            break;
        }
    }

    return 0; 
}