#include <iostream>

#define MAX_NUM 100
using namespace std;

int n,m;
int arr[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];

bool InRange(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m;
}

bool CanGo(int x, int y){
    return InRange(x,y) && (arr[x][y] != 0 ) && (visited[x][y] == false);
}
void DFS(int x, int y){
    int dx[2] = {1,0};
    int dy[2] = {0,1};

    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(CanGo(nx,ny)){
            visited[nx][ny] = true;
            DFS(nx,ny);
        }
    }
    return;

}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    if(visited[n-1][m-1])
        cout << 1;
    else
        cout << 0;
    return 0;
}