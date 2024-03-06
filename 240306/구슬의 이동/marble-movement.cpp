#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_N 50
#define ASCII_NUM 128
#define DIR_NUM 4

using namespace std;

int n,m,t,k;
vector<tuple<int,int,int>> grid[MAX_N][MAX_N];
vector<tuple<int,int,int>> next_grid[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

tuple <int,int,int> NextPos(int x, int y, int vnum, int move_dir){
    int dx[DIR_NUM] = {-1,0,0,1};
    int dy[DIR_NUM] = {0,1,-1,0};

    while(vnum--){
        int nx = x+dx[move_dir], ny = y+dy[move_dir];

        if(!InRange(nx,ny)){
            move_dir = 3-move_dir;
            nx = x+dx[move_dir]; ny = y+dy[move_dir];
        }
        x = nx; y = ny;
    }
    return make_tuple(x,y,move_dir);
}

void MoveAll(){
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++){
            for(int i=0; i<(int) grid[x][y].size(); i++){
                int v, num, move_dir;
                tie(v,num,move_dir) = grid[x][y][i];

                int next_x, next_y, next_dir;
                tie(next_x, next_y, next_dir) = NextPos(x,y,-v, move_dir);
                next_grid[next_x][next_y].push_back(
                    make_tuple(v,num,next_dir)
                );
            }
        }
}

void SelectMarbles(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if((int) next_grid[i][j].size() >= k){
                sort(next_grid[i][j].begin(), next_grid[i][j].end());
                while((int) next_grid[i][j].size() >k)
                    next_grid[i][j].pop_back();
            }
}

void Simulate(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            next_grid[i][j].clear();
        
    MoveAll();
    SelectMarbles();
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = next_grid[i][j];
}

int main(){
    cin >> n >> m >> t >> k;

    int dir_mapper[ASCII_NUM];
    dir_mapper['U'] = 0;
    dir_mapper['R'] = 1;
    dir_mapper['L'] = 2;
    dir_mapper['D'] = 3;

    for(int i=0; i<m; i++){
        int r,c,v; char d;
        cin >> r >> c >> d >> v;

        grid[r-1][c-1].push_back(
            make_tuple(-v,(-i+1),dir_mapper[d])
        );
    }

    while(t--)
        Simulate();
    
    int ans = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans+= (int) grid[i][j].size();

    cout << ans;
    return 0;
    
}