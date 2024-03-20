#include <iostream>
#include <queue>
#define MAX_N 100

using namespace std;

int n,m;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<pair<int,int>> q;
int order;

bool InRange(int x, int y){
    return 0 <= x && x < n && y >= 0 && y <m;
}

bool CanGo(int x, int y){
    if(!InRange(x,y))
        return false;
    if(visited[x][y] || arr[x][y] == 0)
        return false;
    return true;
}

void Push(int x, int y){
    arr[x][y] == order++;
    visited[x][y] = true;
    q.push(make_pair(x,y));
}

void BFS(){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while(!q.empty()){
        pair<int,int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(CanGo(nx, ny))
                Push(nx,ny);
        }

    }
}
int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    Push(0,0);
    BFS();

    if(visited[n-1][m-1] == true)
        cout << 1;
    else
        cout << 0;
    // 여기에 코드를 작성해주세요.
    return 0;
}