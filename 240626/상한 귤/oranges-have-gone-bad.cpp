#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 101

using namespace std;

int n,k;
int grid[MAX_N][MAX_N]; // 귤 위치 들어있는 곳
int ans[MAX_N][MAX_N]; // 귤 위치 + 시간 정보 들어있음
bool visited[MAX_N][MAX_N]; // 한번 상한 건 다시 방문할 필요 없긴해.  
queue <pair<int, int> > q; // 상한 귤 위치 정보 포함됨
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//1. 상한 귤 찾기 - 반복.
//2. 상하좌우 인접한 귤 상하기. 시간 기록하는 grid에 1초..증가.. 
// 귤 상했다고 정보 수정하기. 
// while 문 다 돌리고 나서 남아있는 귤 -2로 수정
// 0은 -1 로 수정. 처음부터 비어있던 칸은 
bool InRange(int x, int y){
    return x>=0 && x <n && y>=0 && y<n;
}

bool CanGo(int x, int y){
    if(grid[x][y] == 0)
        return false;
    if(visited[x][y] == true)
        return false;
    if(InRange(x,y) == false)
        return false;
    return true;
}

void bfs(){
    while(q.empty() == false){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(CanGo(nx,ny) == true && grid[x][y] == 2){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                ans[nx][ny] = ans[x][y] + 1;
                grid[nx][ny] = 2;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            if(grid[i][j] == 1 && ans[i][j]== 0)
                ans[i][j] = -2;
            if(grid[i][j] == 0)
                ans[i][j] = -1;
        }
    }
}
int main() {

    cin >> n >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    ans[i][j] = 0;
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}