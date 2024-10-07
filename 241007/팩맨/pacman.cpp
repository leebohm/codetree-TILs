#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_T 25
#define MAX_N 4
#define DIR_NUM 8
#define P_DIR_NUM 4
#define MAX_DECAY 2

using namespace std;

int n = 4;
int m,t;

int monster[MAX_T+1][MAX_N][MAX_N][DIR_NUM];

int dead[MAX_N][MAX_N][MAX_DECAY+1];

int dx[DIR_NUM] = {-1,-1,0,1,1,1,0,-1};
int dy[DIR_NUM] = {0,-1,-1,-1,0,1,1,1};

int p_dx[P_DIR_NUM] = {-1,0,1,0};
int p_dy[P_DIR_NUM] = {0,-1,0,1};

int px, py;

int t_num = 1;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y){
    return InRange(x,y) && dead[x][y][0] == 0 && dead[x][y][1] == 0
        && make_pair(x,y) != make_pair(px,py);
}


tuple<int,int,int> GetNextPos(int x, int y, int move_dir){
    for(c_dir = 0; c_dir < DIR_NUM; c_dir++){
        int n_dir = (move_dir + c_dir + DIR_NUM) % DIR_NUM;
        int nx = x+dx[n_dir];
        int ny = y+dy[n_dir];
        if(CanGo(nx,ny)){
            return make_tuple(nx,ny,n_dir);
        }
    }

    return make_tuple(x,y, move_dir);
}

void MoveM(){

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<DIR_NUM; k++){
                tuple<int,int,int>  next_pos = GetNextPos(i,j,k);
                int x, y, next_dir;
                tie(x,y, next_dir) = next_pos;
                monster[t_num][x][y][next_dir] += monster[t_num-1][i][j][k];
            }
}

int GetKilledNum(int dir1, int dir2, int dir3){
    int dirs[] = {dir1, dir2, dir3};
    int x = px, y = py;

    vector<pair<int,int> > v_pos;

    for(int i=0; i<3; i++){
        int nx = x+p_dx[dirs[i]], ny = y+p_dy[dirs[i]];
        if(!InRange(nx,ny))
            return -1;
        
        if(find(v_pos.begin(), v_pos.end(), make_pair(nx,ny)) == v_pos.end()){
            for(int j= 0; j<DIR_NUM; j++)
                killed_num += monster[t_num][nx][ny][j];
            v_pos.push_back(make_pair(nx,ny));
        }
        x = nx; y = ny;
    }
    return killed_num;
}

void DoKill(tuple<int,int,int> best_route){
    int dir1, dir2, dir3;
    tie(dir1, dir2, dir3) = best_route;

    int dirs[] = {dir1, dir2, dir3};
    for(int i=0; i<3; i++){
        int nx = px + p_dx[dirs[i]] , ny = py + p_dy[dirs[i]];

        for(int j=0; j<DIR_NUM; j++){
            dead[nx][ny][MAX_DECAY] += monster[t_num][nx][ny][j];
            monster[t_num][nx][ny][j] = 0;
        }

        px = nx; py = ny;
    }
}

void MoveP(){
    int max_cnt = -1;
    tuple<int,int,int> best_route;

    for(int i=0; i<P_DIR_NUM; i++)
        for(int j=0; j<P_DIR_NUM; j++)
            for(int k = 0; k<P_DIR_NUM; k++){
                int m_cnt = GetKilledNum(i,j,k);
                if(m_cnt > max_cnt){
                    max_cnt = m_cnt;
                    best_route = make_tuple(i,j,k);
                }
            }

    DoKill(best_route);
}

void DecayM(){

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            for(int k= 0; k<MAX_DECAY; k++)
                dead[i][j][k] = dead[i][j][k+1];
            dead[i][j][MAX_DECAY] = 0;
        }
}

void AddM(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k= 0; k<DIR_NUM; k++)
                monster[t_num][i][j][k] += monster[t_num-1][i][j][k];
}

void Simulate(){
    MoveM();

    MoveP();
    
    DecayM();

    AddM();
}

int CountMonster(){
    int cnt = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<DIR_NUM; k++)
                cnt+= monster[t][i][j][k];
    return cnt;
}

int main(){
    cin >> m >> t;
    cin >> px >> py;
    px--; py--;

    for(int i=0; i<m; i++){
        int mx, my, mdir;
        cin >> mx >> my >> mdir;

        monster[0][mx-1][my-1][mdir-1]++;
    }

    while(t_num <= t){
        Simulate();
        t_num++;
    }
    cout << CountMonster();
    return 0;
}