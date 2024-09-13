#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 21
#define MAX_M 31

struct Player{
    int x;
    int y;
    int d;
    int s;
    int gun;
    Player(int p, int q, int r, int t, int u) : x(p), y(q), d(r),s(t),gun(u){};
};


int n,m,k; // n * n: 격자크기, m : 플레이어 숫자, k : 라운드 수
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
priority_queue<int> gun_board[MAX_N][MAX_N]; //총 있는 board
int player_board[MAX_N][MAX_N];
int score[MAX_M];
Player *player_list[MAX_M]; // player struct 배열 

bool InRange(int x, int y){
    return x >= 1 && x <=n && y >= 1 && y <=n; 
}

bool move(int idx){
    int x = player_list[idx]->x;
    int y = player_list[idx]->y;
    int dir = player_list[idx]->d;

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(InRange(nx,ny) == false){ // 격자 밖을 벗어나면 방향 바꾸기!
        dir = (dir + 2) % 4;
    }
    player_board[x][y] = 0;
    x += dx[dir];
    y += dy[dir];
    player_list[idx]->x = x;
    player_list[idx]->y = y;
    player_list[idx]->d = dir;

    if(player_board[x][y] != 0){ // 다른 player 있는 경우
        return false;
    }
    else{
        player_board[x][y] = idx; // 보드판 위에 player 정보 update 하기 
        return true;
    }
}

void get_gun(int idx){
    int x = player_list[idx]->x;
    int y = player_list[idx]->y;
    int gun_origin = player_list[idx]->gun;
    int gun_power = gun_board[x][y].top(); 
    if(gun_power == 0) // 총이 없는 경우 끝남
        return;
    // 이미 총 가지고 있는 경우 비교해서 가장 공격력이 더 쎈 총을 획득.
    if(gun_origin < gun_power){
        player_list[idx]->gun = gun_power;
        gun_board[x][y].pop();
        gun_board[x][y].push(gun_origin);
    }
    // 원래 가지고 있는 총이 더 쎈 경우 총 줍지 않음. 
}

void Lose(int idx){
    int gun_power = player_list[idx]->gun;
    int x = player_list[idx]->x;
    int y = player_list[idx]->y;
    gun_board[x][y].push(gun_power);
    player_list[idx]->gun = 0; // 총 내려놓기 

    int dir = player_list[idx]->d;
    while(true){
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(InRange(nx,ny)== false){
                dir = (dir+1) % 4;
        } 
        else if(player_board[nx][ny]!=0)
                dir = (dir+1) % 4;
        else
            break;
    }
    player_board[x][y] = 0;
    x += dx[dir];
    y += dy[dir];
    player_board[x][y] = idx; // 보드에 바뀐 위치 정보 업데이트
    player_list[idx]->x = x;
    player_list[idx]->y = y;
    player_list[idx]->d = dir; // 배열에 위치 정보 업데이트
}

void Win(int idx){
    int x = player_list[idx]->x;
    int y = player_list[idx]->y;
    int gun_origin = player_list[idx]->gun;
    int gun_power = gun_board[x][y].top(); 

    if(gun_origin < gun_power){
        gun_board[x][y].pop();
        player_list[idx]->gun = gun_power;
        gun_board[x][y].push(gun_origin);
    }
}

void fight(int idx){
    
    int x = player_list[idx]->x;
    int y = player_list[idx]->y;

    int o_idx = player_board[x][y]; // 원래 있던 참가자 인덱스
    int o_power = player_list[o_idx]-> s + player_list[o_idx]->gun;
    int v_power = player_list[idx]->s + player_list[idx]->gun;

    int win_idx, lose_idx;
    // 1. 같은 경우
    if(o_power == v_power){
        if(player_list[idx]-> s > player_list[o_idx]-> s){
            win_idx = idx;
            lose_idx = o_idx;
        }
        else{
            win_idx = o_idx;
            lose_idx = idx;
        }
    }

    // 2.다른 경우
    else if(o_power > v_power){
        win_idx = o_idx;
        lose_idx = idx;
    }
    else{
        win_idx = idx;
        lose_idx = o_idx;
    }
    // 점수 얻기 
    score[win_idx] += abs(o_power - v_power);
    Lose(lose_idx);
    Win(win_idx);
}

void PrintScore(){
    for(int i=1; i<=m; i++){
        cout << score[i] << " ";
    }
    cout << endl;
}
int main() {
    
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int tmp;
            cin >> tmp;
            gun_board[i][j].push(tmp);
        }
    }

    for(int i=1; i<=m; i++){
        int x,y,d,s;
        cin >> x >> y >> d >> s;
        player_list[i] = new Player(x,y,d,s,0);
        player_board[x][y] = i;
    }

    while(k--){
        for(int i=1; i<=m; i++){
            bool flag = move(i);
            if(flag == true) // 다른 플레이어 없는 경우
                get_gun(i);
            else
                fight(i);
            //PrintScore();
        }
    }
    
    PrintScore();

    return 0;
}