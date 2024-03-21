#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
queue<pair<int,int>> q;

bool InRange(int x, int y){
    return x >= 0 && x <= n && y >= 0 && y<n;
}

void BFS(){
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int x,y;
        tie(x,y) = pos;

        for(int i = 0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny) && !visited[nx][ny]){
                step[nx][ny] = step[x][y]+1;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {

    cin >> n;

    int r1,c1,r2,c2;

    cin >> r1 >> c1 >> r2 >> c2;

    r1--;c1--;r2--;c2--;

    q.push(make_pair(r1,c1));
    visited[r1][c1] = true;

    step[r2][c2] = -1;
    BFS();
    if(r1 == r2 && c1 == c2)
        cout << 0;
    else
        cout << step[r2][c2] ;
    // 여기에 코드를 작성해주세요.
    return 0;
}