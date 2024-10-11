#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_N 100001

int n,m;
vector<pair<int,long long> > edges[MAX_N];
long long dist[MAX_N];
priority_queue<pair<long long,int> > pq;
    

int main() {
    
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        long long z;
        cin >> x >> y >> z;
        edges[x].push_back(make_pair(y,z));
        edges[y].push_back(make_pair(x,z));
    }
    for(int i=1; i<=n; i++)
        dist[i] = (long long) 1e15;
    
    dist[n] = 0;

    pq.push(make_pair(0LL,n));

    while(pq.empty() == false){
        long long c_dist; int idx;
        tie(c_dist, idx) = pq.top(); pq.pop();
        c_dist = -c_dist;

        for(int i=0; i<edges[idx].size(); i++){
            int target_idx; long long target_dist;
            tie(target_idx, target_dist) = edges[idx][i];
            long long new_dist = c_dist + target_dist;
            if(dist[target_idx] > new_dist){
                dist[target_idx] = new_dist;
                pq.push(make_pair(-new_dist, target_idx));
            }
        }
    }

    long long ans = 0;
    for(int i=1; i<=n-1; i++)
        ans = max(ans, dist[i]);
    cout << ans << endl;

    return 0;
}