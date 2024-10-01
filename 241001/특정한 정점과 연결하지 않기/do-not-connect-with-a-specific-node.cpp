#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int n,m;
int a,b,k;

int uf[MAX_N];
int sz[MAX_N];
bool visited[MAX_N];

vector<int> group_list;

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

    for(int i=1; i<=m;i++){
        int x, y;
        cin >> x >> y;
        Union(x,y);
    }

    cin >> a >> b >> k;

    int ra = Find(a);
    int rb = Find(b);

    for(int i=1; i<=n; i++){
        int ri = Find(i);

        if(ri == ra || ri == rb)
            continue;
        
        if(visited[ri])
            continue;
        visited[ri] = true;
        group_list.push_back(sz[ri]);
    }

    int sz_a = sz[ra];

    sort(group_list.begin(), group_list.end(), greater<int> ());

    for(int i=0; i < min(k, (int) group_list.size()); i++)
        sz_a += group_list[i];
    
    cout << sz_a;
    return 0;
}