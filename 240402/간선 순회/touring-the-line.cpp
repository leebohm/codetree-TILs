#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50000

using namespace std;

// 변수 선언:
int n, d;
vector<pair<int, int> > edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist_node[MAX_N + 1];
int dist[MAX_N + 1];
pair<int, int> max_dist;
int last_node;

// 모든 노드의 정점을 탐색하는 DFS를 진행합니다.
void DFS(int x) {
    visited[x] = true;

    for(int i = 0; i < edge[x].size(); i++) {
        int y, dis;
        tie(y, dis) = edge[x][i];

        // 이미 방문한 정점이면 스킵합니다.
        if(visited[y]) continue;

        dist_node[y] = dist_node[x] + 1;
        dist[y] = dist[x] + dis;

        pair<int, int> cur_dist = {dist_node[y], -dist[y]};

        // 현재 정점을 기준으로 가장 먼 노드를 찾습니다.
        // 지나는 간선의 수가 최대가 되도록 하며,
        // 동일한 경우 거리의 합이 최소가 되도록 합니다.
        if(cur_dist > max_dist) {
            max_dist = cur_dist;
            last_node = y;
        }

        DFS(y);
    }
}

int main() {
    // 입력:
    cin >> n >> d;

    // n - 1개의 간선 정보를 입력받습니다.
    for(int i = 1; i <= n - 1; i++) {
        int x, y, dis;

        cin >> x >> y >> dis;

        edge[x].push_back({y, dis});
        edge[y].push_back({x, dis});
    }

    // DFS를 통해 가장 먼 노드를 찾습니다.
    DFS(1);

    // 가장 먼 노드에서 시작해 다시 한번 DFS를 돌려 트리의 가장 긴 거리를 찾습니다.
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist_node[i] = 0;
        dist[i] = 0;
    }

    DFS(last_node);

    // 꼭 필요한 날짜의 수를 출력합니다.
    //cout <<  max_dist.first << " " << max_dist.second << endl;
    cout << 1 + (-max_dist.second ) / d;
    return 0;
}