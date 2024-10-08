#include <iostream>

#define MAX_N 20
#define MAX_M 400
#define DIR_NUM 4
#define OFFICE 1

using namespace std;

int n,m,k;
int grid[MAX_N][MAX_N];
int coolness[MAX_N][MAX_N];

int temp[MAX_N][MAX_N];

int dx[DIR_NUM] = {-1,0,0,1};
int dy[DIR_NUM] = {0,-1,1,0};

bool block[MAX_N][MAX_N][DIR_NUM];

bool visited[MAX_N][MAX_N];

int elapsed_time;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int RevDir(int x_diff, int y_diff){
    for(int i=0; i<4; i++)
        if(dx[i] == x_diff && dy[i] == y_diff)
            return i;
        
    return -1;
}

void Spread(int x, int y, int move_dir, int power){
    if(power == 0)
        return;
    
    visited[x][y] = true;
    coolness[x][y] += power;

    int nx = x+dx[move_dir];
    int ny = y+dy[move_dir];

    if(InRange(nx,ny) && !visited[nx][ny] && !block[x][y][move_dir])
        Spread(nx,ny,move_dir,power-1);
    
    if(dx[move_dir]==0){
        int nxs[] = {x+1, x-1};
        for(int i=0; i<2; i++){
            int nx = nxs[i];
            int ny = y+dy[move_dir];
            if(InRange(nx,ny) && !visited[nx][ny] && !block[x][y][RevDir(nx-x,0)]&& !block[nx][y][move_dir])
                Spread(nx,ny,move_dir,power -1);
        }
    }

    else {
        int nys[] = {y+1, y-1};
        for(int i=0; i<2; i++){
            int nx = x+dx[move_dir];
            int ny = nys[i];
            if(InRange(nx,ny) && !visited[nx][ny] && !block[x][y][RevDir(0,ny-y)] && !block[x][ny][move_dir])
                Spread(nx,ny,move_dir,power - 1);
        }
    }
}

void ClearVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}

void Blow(){
    for(int x = 0; x<n; x++)
        for(int y = 0 ;y<n; y++)
            if(grid[x][y] >= 2){
                int move_dir = (grid[x][y] <= 3) ? (3 - grid[x][y]) : (grid[x][y] - 2);
                int nx = x+dx[move_dir];
                int ny = y+dy[move_dir];
                ClearVisited();
                Spread(nx,ny,move_dir,5);
            }
}

int GetMixedCoolness(int x, int y){
    int remaining_c = coolness[x][y];
    for(int i=0; i<DIR_NUM; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(InRange(nx,ny) && !block[x][y][i]){
            if(coolness[x][y] > coolness[nx][ny])
                remaining_c -= (coolness[x][y] - coolness[nx][ny]) / 4;
            else    
                remaining_c += (coolness[nx][ny] - coolness[x][y]) / 4;
        }
    }
    return remaining_c;
}

void Mix(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = GetMixedCoolness(i,j);
        
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            coolness[i][j] = temp[i][j];
}


bool IsOuterWall(int x, int y){
    return x == 0 || x == n-1 || y == 0 || y == n-1;
}

void Drop(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(IsOuterWall(i,j) && coolness[i][j] > 0)
                coolness[i][j]--;
}

void Simulate(){
    Blow();

    Mix();

    Drop();

    elapsed_time++;
}

bool End(){
    if(elapsed_time > 100)
        return true;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(grid[i][j] == OFFICE && coolness[i][j] < k)
                return false;
    
    return true;
}

int main(){

    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    for(int i=0; i<m; i++){
        int bx,by,bdir;
        cin >> bx >> by >> bdir;
        bx--;by--;
        block[bx][by][bdir] = true;

        int nx = bx + dx[bdir];
        int ny = by + dy[bdir];

        if(InRange(nx,ny))
            block[nx][ny][3-bdir] = true;
    }

    while(!End())
        Simulate();

    if(elapsed_time <= 100)
        cout << elapsed_time;
    else
        cout << -1;
    return 0;
}