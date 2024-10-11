#include <iostream>
#include <vector>
#include <tuple>

#define MAX_M 1001
#define INF (long long) 1e17 +1

using namespace std;

int a,b,n,m = 1000;
pair<long long, long long > graph[MAX_M][MAX_M];
bool visited[MAX_M];

pair<long long, long long> dist[MAX_M];

int main(){

    cin >> a >> b >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            graph[i][j] = make_pair(INF, 0);
        }
        graph[i][i] = make_pair(0,0);
    }

    for(int i=1; i<=n; i++){
        int cost, stop_num;
        cin >> cost >> stop_num;

        vector<int> stops(stop_num);
        for(int j=0; j<stop_num; j++)
            cin >> stops[j];

        for(int j=0; j<stop_num; j++){
            for(int k= j+1; k <stop_num; k++){
                graph[stops[j]][stops[k]] = min(graph[stops[j]][stops[k]], 
                                            make_pair((long long) cost, (long long) k-j));
            }
        }
    }

    for(int i=1; i<=m; i++)
        dist[i] = make_pair(INF, 0);
    
    dist[a] = make_pair(0,0);

    for(int i=1; i<=m; i++){
        int min_index = -1;
        for(int j=1; j<=m; j++){
            if(visited[j])
                continue;
            
            if(min_index  == -1 || dist[min_index] > dist[j])
                min_index = j;
        }

        visited[min_index] = true;
        long long min_cost, min_time;
        tie(min_cost, min_time) = dist[min_index];

        for(int j=1; j<=m; j++){
            long long cost, time;
            tie(cost, time) = graph[min_index][j];
            dist[j] = min(dist[j], make_pair(min_cost + cost, min_time + time));
        }
    }

    if(dist[b] == make_pair(INF, 0LL))
        dist[b] = make_pair(-1,-1);
    
    long long min_cost, min_time;
    tie(min_cost, min_time) = dist[b];

    cout << min_cost << " " << min_time;
    return 0;
}