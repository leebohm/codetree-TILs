#include <iostream>
#include <queue>
#include <tuple>

#define MAX_NM 100
using namespace std;

int n,m;
int arr[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];
int step[MAX_NM][MAX_NM];

queue<pair<int,int>> q;

bool InRange(int x, int y){
    return x>=0 && x < n && y>=0 && y<m;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(arr[x][y] == 0 || visited[x][y])
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int x,y;
        tie(x,y) = pos;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
                step[nx][ny] = step[x][y] +1;
            }
        }
    }
}
int main() {
    cin >> n >> m;

    for(int i=0; i<n ; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    
    q.push(make_pair(0,0));
    visited[0][0] = true;
    BFS();

    cout << step[n-1][m-1];
    // 여기에 코드를 작성해주세요.
    return 0;
}