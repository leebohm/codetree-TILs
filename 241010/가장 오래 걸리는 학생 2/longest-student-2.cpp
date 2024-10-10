#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#define MAX_N 100001
int dist[MAX_N];
priority_queue<pair<int,int> > pq;
int n,m;
vector<pair<int,int> > edges[MAX_N];

void PrintDist(){
    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main() {

    cin >>  n >> m;
    for(int i=1; i<=n; i++)
        dist[i] = (int) 1e9;
    dist[n] = 0;
    for(int i=1; i<=m; i++){
        int x,y,d;
        cin >> x >> y >> d;
        edges[y].push_back(make_pair(x,d));
    }    
    pq.push(make_pair(-0,n));

    while(pq.empty() == false){
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        min_dist = -min_dist;
        pq.pop();
        if(min_dist != dist[min_index])
            continue;
        
        for(int i=0; i<edges[min_index].size(); i++){
            int y,d;
            tie(y,d) = edges[min_index][i];
            int new_dist = dist[min_index] + d;
            if(dist[y] > new_dist){
                dist[y] = new_dist;
                pq.push(make_pair(-new_dist, y));
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n-1; i++)
        if(dist[i] != (int) 1e9)
            ans = max(dist[i], ans);
    cout << ans << endl;
    return 0;
}