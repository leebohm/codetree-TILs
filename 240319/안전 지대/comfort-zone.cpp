#include <iostream>

#define MAX_NM 50
using namespace std;

int n,m,k;
int arr[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

void ResetVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j] = false;
}

bool InRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y){
    if(visited[x][y] == true) return false;
    if(InRange(x,y) == false || arr[x][y] <= k)
        return false;
    return true;
}

void DFS(int x, int y){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(CanGo(nx,ny)){
            visited[nx][ny] = true;
            DFS(nx,ny);
        }
    }
}

int Simulation(){
    int comfort_zone_num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(CanGo(i,j)){
                comfort_zone_num++;
                DFS(i,j);
            }
        }
    }
    return comfort_zone_num;
}

int main() {

    cin >> n >> m;

    int max_k = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            max_k = max(max_k, arr[i][j]);
        }
            
    int ans = 1;
    int min_k = 0;
    for(int i=1; i<=max_k; i++){
        k = i;
        ResetVisited();
        int tmp = Simulation();
        if(ans < tmp){
            min_k = k;
            ans = tmp;
        }
        
    }

    cout << ans << " " << min_k ;
    // 여기에 코드를 작성해주세요.
    return 0;
}