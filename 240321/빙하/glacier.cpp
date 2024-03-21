#include <iostream>
#include <queue>

#define MAX_NM 200

using namespace std;

int n,m;
int arr[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];
int ice_num;
int last_ice_num;
queue<pair<int,int>> q;
int t;

bool InRange(int x, int y){
    return x >=0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(arr[x][y] == 1 || visited[x][y] == true)
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(CanGo(nx,ny)){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void RemoveIce(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]){
                int dx[4] = {1,0,-1,0};
                int dy[4] = {0,1,0,-1};

                for(int k = 0; k < 4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(InRange(nx,ny) && arr[nx][ny] == 1)
                        arr[nx][ny] = 0;
                }
            }
        }
    }
}

void InitializedVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            visited[i][j] = false;
}

void CountIceNum(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(arr[i][j])
                ice_num++;
}

void Simulation(){
    while(1){
        t++;
        InitializedVisited();
        q.push(make_pair(0,0));
        visited[0][0] = true;
        BFS();
        last_ice_num = ice_num;
        ice_num = 0;
        RemoveIce();
        CountIceNum();
        if(ice_num == 0) break;
    }

}

int main() {
    cin >>  n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j])
                ice_num++;
        }

    Simulation();
    cout << t <<" "<< last_ice_num ;
    // 여기에 코드를 작성해주세요.
    return 0;
}