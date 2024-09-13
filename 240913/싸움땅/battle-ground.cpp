#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

#define MAX_N 20
#define MAX_M 30
#define DIR_NUM 4
#define Player tuple<int,int,int,int,int,int>
#define EMPTY make_tuple(-1,-1,-1,-1,-1,-1)

using namespace std;

int n,m,k;

// 각 칸마다 놓여있는 총 목록을 관리합니다.
vector<int> gun[MAX_N][MAX_N];

// 각 칸마다 플레이어 정보를 관리
// 순서대로 num, x, y, d, s, a 정보를 관리
// (x,y) 위치에서 방향 d를 보고 있으며
// 초기 능력치가 s인 num번 플레이어가 
// 공격력이 a인 총을 들고 있음을 뜻한다
// 총이 없으면 a는 0이다.

Player players[MAX_M];

// 입력으로 주어지는
// 방향 순서대로
// dx, dy를 정의합니다.
int dx[DIR_NUM] = {-1,0,1,0};
int dy[DIR_NUM] = {0,1,0,-1};

// 플레이어들의 포인트 정보를 기록합니다.
int points[MAX_M];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 현재 위치에서 방향 d를 보고 있을 때 그 다음 위치와 방향을 찾아줍니다.
tuple<int,int,int> GetNext(int x, int y, int d){
    int nx = x+dx[d], ny = y + dy[d];
    // 격자를 벗어나면 방향을 뒤집어 반대 방향으로 한 칸 이동합니다.
    if(!InRange(nx,ny)){
        d = (d < 2) ? (d + 2) : (d - 2);
        nx = x + dx[d], ny = y + dy[d];
    }

    return make_tuple(nx,ny,d);
}

// 해당 칸에 있는 player를 찾아줍니다. 
// 없다면 empty를 반환합니다.
Player FindPlayer(pair<int,int> pos){
    for(int i=0; i<m; i++){
        int x, y;
        tie(ignore, x, y, ignore,ignore,ignore) = players[i];

        if(pos == make_pair(x,y))
            return players[i];
    }
    return EMPTY;
}

// player p의 정보를 갱신해줍니다. 
void Update(Player p){
    int num;
    tie(num, ignore, ignore, ignore, ignore, ignore) = p;

    for(int i=0; i<m; i++){
        int num_i;
        tie(num_i, ignore, ignore, ignore, ignore, ignore) = players[i];

        if(num_i == num){
            players[i] = p;
            break;
        }
    }
}

void Move(Player p, pair<int,int> pos){
    int num, x, y, d, s, a;
    tie(num, x, y, d, s, a) = p;

    int nx, ny;
    tie(nx,ny) = pos;

    gun[nx][ny].push_back(a);
    sort(gun[nx][ny].begin(), gun[nx][ny].end(), greater<int>());
    a = gun[nx][ny][0];

    p = make_tuple(num, nx,ny,d,s,a);
    Update(p);
}

void LoserMove(Player p){
    int num, x, y, d,s,a;
    tie(num, x, y, d, s, a) = p;

    gun[x][y].push_back(a);

    for(int i=0; i<4; i++){
        int ndir = (d+i) % 4;
        int nx = x + dx[ndir], ny = y + dy[ndir];
        if(InRange(nx,ny) && FindPlayer(make_pair(nx,ny)) == EMPTY){
            p = make_tuple(num,x,y,ndir,s,0);
            Move(p,make_pair(nx,ny));
            break;
        }
    }
}

void Duel(Player p1, Player p2, pair<int,int> pos){
    int num1, d1, s1, a1;
    tie(num1, ignore, ignore, d1, s1, a1) = p1;

    int num2, d2, s2, a2;
    tie(num2, ignore, ignore, d2, s2, a2) = p2;

    if(make_pair(s1+a1, s1) > make_pair(s2+a2,s2)){
        points[num1] += (s1+a1) - (s2+a2);

        LoserMove(p2);

        Move(p1, pos);
    }
    else{
        points[num2] += (s2 + a2) - (s1 + a1);
        LoserMove(p1);
        Move(p2, pos);
    }
}

void Simulate(){
    
    for(int i=0; i<m; i++){
        int num, x, y, d, s,a;
        tie(num, x, y, d, s, a) = players[i];

        int nx,ny,ndir;
        tie(nx,ny,ndir) = GetNext(x,y,d);

        Player next_player = FindPlayer(make_pair(nx,ny));

        Player curr_player = make_tuple(num, nx,ny,ndir, s,a);
        Update(curr_player);

        if(next_player == EMPTY)
            Move(curr_player, make_pair(nx,ny));
        else
            Duel(curr_player, next_player, make_pair(nx,ny));
    }
}

int main(){
    cin >>  n >> m >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            int num;
            cin >> num;
            if(num != 0)
                gun[i][j].push_back(num);
        }

    for(int i=0; i<m; i++){
        int x, y, d, s;
        cin >> x >> y >> d>> s;
        players[i] = make_tuple(i,x-1,y-1,d,s,0);
    }

    while(k--)
        Simulate();

    for(int i=0; i<m; i++)
        cout << points[i] << " ";
    
    return 0;
}