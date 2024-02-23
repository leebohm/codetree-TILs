#include <iostream>
#include <vector>

#define MAX_N 100
#define DIR_NUM 4
#define CCW 0 
#define CW 1

using namespace std;

int n;
int grid[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];

void Shift(int x, int y, int k, int l, int move_dir){
    vector<int> dx, dy, move_nums;

    if(move_dir==CCW){
        dx = {-1,-1,1,1};
        dy = {1,-1,-1,1};
        move_nums = {k,l,k,l};
    }

    else {
        dx = {-1,-1,1,1};
        dy = {-1,1,1,-1};
        move_nums = {l, k, l,k};
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = grid[i][j];
    
    for(int d =0; d<DIR_NUM; d++)
        for(int q=0; q<move_nums[d]; q++){
            int nx = x+dx[d] , ny = y+dy[d];
            temp[nx][ny] = grid[x][y];
            x = nx; y = ny;
        }
    
    for(int i=0; i< n; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = temp[i][j];
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    int x, y, m1, m2, m3, m4, d;

    cin >> x >> y >> m1 >> m2 >> m3 >> m4 >> d;
    Shift(x-1, y-1, m1, m2, d);

    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}