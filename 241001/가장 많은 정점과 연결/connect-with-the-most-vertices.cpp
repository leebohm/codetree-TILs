#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

#define MAX_N 100001

int n, m;
long long k;
vector<int> cost_list;

// 모든 정점이 연결되기 위해 필요한 최소한의 비용을 찾는 프로그램 
int cost[MAX_N];
int uf[MAX_N];
int min_val[MAX_N];
set<int> visited;

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
    
    cin >> n >>  m >> k;

    for(int i=1; i<=n; i++)
        cin >> cost[i];
    
    for(int i=1; i<=n; i++){
        uf[i] = i;
        min_val[i] = INT_MAX;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    } 

    for(int i=1; i<=n; i++){
        int ri = Find(i);
        visited.insert(ri);
        min_val[ri] = min(min_val[ri], cost[i]);
    }

    for(int i=1; i<=n; i++){
        if(visited.find(i) != visited.end()){
            cost_list.push_back(min_val[i]);
        }
    }
    sort(cost_list.begin(), cost_list.end());

    int sum1 = cost_list[0];
    int num = (int) cost_list.size();
    long long ans = 0;
    for(int i=1; i<num; i++){
        ans += (sum1 + cost_list[i]);
    }
    if(ans > k)
        cout << "NO";
    else
        cout << ans;


    
    return 0;
}