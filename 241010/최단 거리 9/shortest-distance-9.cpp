#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_N 1001

int n,m,a,b;
vector<pair<int,long long> > edges[MAX_N];
long long min_dist;
long long dist[MAX_N];
priority_queue<pair<long long,int> > pq;
int path[MAX_N];

void PrintDist(){
    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main() {

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        dist[i] = (int) 1e9;
    
    for(int i=0; i<m; i++){
        int x,y;
        long long d;
        cin >> x >> y >> d;
        edges[x].push_back(make_pair(y,d));
        edges[y].push_back(make_pair(x,d));
    }
    cin >>a  >> b;
    dist[a] = 0;
    pq.push(make_pair(0,a));

    while(pq.empty()== false){
        long long min_dist;
        int min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();
        min_dist = -min_dist;
        if(min_dist != dist[min_index])
            continue;

        for(int i=0; i<(int) edges[min_index].size(); i++){
            int y; long long d;
            tie(y,d) = edges[min_index][i];
            long long new_dist = dist[min_index] + d;
            if(dist[y] > new_dist){
                dist[y] = new_dist;
                pq.push(make_pair(-new_dist, y));
                path[y] = min_index;
            }
        }
    }

    cout << dist[b] << endl;
    
    int x = b;
    vector<int> vec;
    vec.push_back(x);
    while(x != a){
        x = path[x];
        vec.push_back(x);
    }
    for(int i=(int) vec.size()-1; i>=0; i--)
        cout << vec[i]  << " ";
    
    return 0;
}