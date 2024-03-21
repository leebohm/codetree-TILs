#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100
using namespace std;

int n,h,m;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

queue<pair<int,int>> q;

// 0 : 이동가능
// 1 : 벽이 있는 곳
// 2 : 사람이 서 있음
// 3 : 비를 피할 수 있는 공간 

bool InRange(int x, int y){
    return x>=0 && x <n && y >= 0 && y <n;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(visited[x][y] == true || arr[x][y] == 1)
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
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                if(step[nx][ny] > 0)
                    step[nx][ny] = min(step[nx][ny], step[x][y]+1);
                else 
                    step[nx][ny] = step[x][y]+1;
            }
        }
    }
}

void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(arr[i][j] == 0 || arr[i][j] == 3 || arr[i][j] == 1)
                cout << 0 << " ";
            else if(step[i][j] == 0){
                cout << -1 << " ";}
            else{
                cout << step[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> h >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 3){
                q.push(make_pair(i,j));
                visited[i][j] = true;
            }
        }
    
    BFS();
    Output();
            
    // 여기에 코드를 작성해주세요.
    return 0;
}