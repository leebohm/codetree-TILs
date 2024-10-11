#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N 100001

using namespace std;

int n,m,a,b,c;
vector<pair<int,int> > edges[MAX_N];
int abc_dist[MAX_N];

void Dijkstra(int idx){
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,idx));

    int dist[n+1] = {0};
    for(int i=1; i<=n; i++)
        dist[i] = (int) 1e9;
    dist[idx] = 0;
    while(pq.empty() == false){
        int m_dist, k;
        tie(m_dist, k) = pq.top(); pq.pop();
        m_dist = -m_dist;
        for(int i=0; i<edges[k].size(); i++){
            int y_dist, n_idx;
            tie(n_idx,y_dist) =edges[k][i];
            int new_dist = m_dist + y_dist;
            if(dist[n_idx] > new_dist){
                dist[n_idx] = new_dist;
                pq.push(make_pair(-new_dist,n_idx));
            }
        }
    }
    for(int i=1; i<=n; i++){
        abc_dist[i] = min(abc_dist[i], dist[i]);
    }
}

int main(){

    cin >> n >> m;
    cin >> a >> b >> c;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        edges[x].push_back(make_pair(y,z));
        edges[y].push_back(make_pair(x,z));
    }
    for(int i=1; i<=n; i++)
        abc_dist[i] = (int) 1e9;

    Dijkstra(a);
    Dijkstra(b);
    Dijkstra(c);

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, abc_dist[i]);
    }
    cout << ans;

    return 0;

}