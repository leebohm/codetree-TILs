#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

#define MAX_N 1001

int a,b,n;
vector<tuple<int,int,int> > edges[MAX_N];
priority_queue<tuple<int,int,int> > pq;
int dist[MAX_N];
int path[MAX_N];

int main() {
    cin >> a >> b >> n;

    for(int i=1; i<=2*n; i++){
        int cost, num;
        cin >> cost >> num;
        int arr[num] = {0};
        for(int j=0; j<num; j++)
            cin >> arr[j];
        for(int j=0; j<num-1; j++){
            int x = arr[j];
            int y = arr[j+1];
            edges[x].push_back(make_tuple(y,i,cost)); // 다음 노드, 인덱스, 비용
        }
    }
    
    pq.push(make_tuple(0,0,a)); // 비용, 인덱스, 노드 번호
    
    for(int i=1; i<=MAX_N; i++)
        dist[i] = (int) 1e9;
    
    dist[a] = 0;

    while(pq.empty() == false){
        int x,idx1,cost;
        tie(cost,idx1,x) = pq.top();
        pq.pop();
        cost = -cost;
        for(int i=0; i<(int) edges[x].size(); i++){
            int y,idx2, cost2;
            tie(y,idx2,cost2) = edges[x][i];
            if(idx2 == idx1){
                if(idx1 == 0){
                    dist[y] = min(dist[y], cost2);
                    dist[x] = y;
                }
                if(dist[y] > dist[x]){
                    dist[y] = min(dist[y], dist[x]);
                    path[x] = y;
                }
                pq.push(make_tuple(-dist[y], idx2, y));
            }
            if(dist[y] > dist[x] + cost2){
                dist[y] = min(dist[y], dist[x] + cost2);
                pq.push(make_tuple(-dist[y],idx2,y));
                path[x] = y;
            }
        }
    }

    cout << dist[b] << " ";
    int x = a;
    int cnt = 0;
    while( x!= b){
        x = path[x];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}