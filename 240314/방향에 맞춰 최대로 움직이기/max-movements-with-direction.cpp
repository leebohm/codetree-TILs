#include <iostream>
#include <algorithm>

#define MAX_N 4
#define DIR_NUM 8

using namespace std;

int n;
int num[MAX_N][MAX_N], move_dir[MAX_N][MAX_N];
int ans;

bool InRange(int x, int y){
    return 0<= x && x <n && 0<= y &&  y<n;
}

bool CanGo(int x, int y, int prev_num){
    return InRange(x,y) && num[x][y] > prev_num;
}

void FindMax(int x, int y, int cnt){

    ans = max(ans, cnt);

    int dx[DIR_NUM] = {-1,-1,0,1,1,1,0,-1};
    int dy[DIR_NUM] = {0,1,1,1,0,-1,-1,-1};
    int d = move_dir[x][y] -1;

    for(int i=0; i<n; i++){
        int nx = x+dx[d] * i, ny = y + dy[d]*i;
        if(CanGo(nx, ny, num[x][y]))
            FindMax(nx,ny, cnt+1);
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> num[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> move_dir[i][j];
    
    int r,c;
    cin >> r >> c;

    FindMax(r-1,c-1,0);
    cout<< ans;

    return 0;
}