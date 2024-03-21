#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N 100
using namespace std;

int n,k;
int arr[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int r1,c1,r2,c2;
vector<pair<int,int>> selected_walls;
vector<pair<int,int>> walls;
queue<pair<int,int>> q;

// 0 : 이동할 수 있는 곳 
// 1 : 벽이 있는 곳

void InitializedVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}

bool InRange(int x, int y){
    return x>=0 && x <n && y >=0 && y <n;
}

bool CanGo(int x, int y){
    if(InRange(x,y)== false)
        return false;
    
    if(tmp[x][y] == 1 || visited[x][y] == true)
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int x, y;
        tie(x,y) = pos;

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(CanGo(nx,ny)){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                
                if(step[nx][ny] == 0)
                    step[nx][ny] = step[x][y]+1;
                else
                    step[nx][ny] = min(step[nx][ny], step[x][y]+1);
            }
        }
    }
}

void InitializedTmp(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            tmp[i][j] == arr[i][j];
}

void RemoveWalls(){
    for(int i=0; i<(int) selected_walls.size(); i++){
        int x,y;
        tie(x,y) = selected_walls[i];
        tmp[x][y] = 0;
    }
}

void Choose(int idx, int cnt){
    if(cnt == k){
        InitializedVisited();
        q.push(make_pair(r1,c1));
        visited[r1][c1] = true;
        InitializedTmp();
        BFS();

    }

    if(idx == (int) walls.size())
        return;

    selected_walls.push_back(walls[idx]);
    Choose(idx +1, cnt+1);
    selected_walls.pop_back();
    Choose(idx+1, cnt);

    
}


int main() {
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                walls.push_back(make_pair(i,j));
            }
        }
            

    cin >> r1 >> c1 >> r2 >> c2;
    r1--;c1--;r2--;c2--;

   

    Choose(0,0);

    if(step[r2][c2] == 0)
        cout << -1;
    else 
        cout << step[r2][c2];
    


    // 여기에 코드를 작성해주세요.
    return 0;
}