#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <queue>

using namespace std;

#define MAX_N 22
#define MAX_M 6
int n, m, k; // n : 격자 크기(n*n), m : 팀의 개수 , k : 라운드 수
// 1 : 머리사람, 2 : 나머지, 3 : 꼬리사람, 4 : 이동선
// 격자 r,c 값은 1 부터 시작. 
int team_cnt = 0;
int board[MAX_N][MAX_N];
int team_board[MAX_N][MAX_N]; // 각 위치가 몇번째 팀인지 팀번호를 저장하기. 
pair<int,int> heads[MAX_M]; // init 할 때 머리 정보 저장
int score = 0;
deque<pair<int,int> > teams[MAX_M]; // 각 팀의 머리부터 꼬리까지 위치 정보 저장

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visited[MAX_N][MAX_N];

void InitVisited(){
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = false;
        }
    }
}

bool InRange(int x, int y){
    return x>=1 && x <=n && y >= 1&& y <= n;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(visited[x][y]== true)
        return false;
    if(board[x][y] == 0 || board[x][y] == 4)
        return false;
    return true;
}

void PrintTeams(){
    for(int i=1; i<=team_cnt; i++){
        int num = (int) teams[i].size();
        cout << "i = " << i << " :  ";
        for(int j=0; j<num; j++){
            cout << teams[i][j].first << teams[i][j].second  << " ";
        }
        cout << endl;
    }
}

void PrintBoard(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void PrintTeamBoard(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << team_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void FindMembers(int idx, int x, int y){

    InitVisited();
 
    teams[idx].push_back(make_pair(x,y)); // 머리 넣기
    visited[x][y] = true;
    bool flag = true;

    while(flag){
        int num = (int) teams[idx].size();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(CanGo(nx,ny) == true ){
                if(num < 2 && board[nx][ny] == 3)
                    continue;
                visited[nx][ny] = true;
                teams[idx].push_back(make_pair(nx,ny));
                x = nx; y = ny;
                if(board[x][y] == 3){
                    flag = false;
                    break;
                }
                else{
                    break;
                }
            }
            
        }
    }
}
bool CanGo2(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(visited[x][y]== true)
        return false;
    if(board[x][y] == 0)
        return false;
    return true;
}

void WriteTeamNum(int idx){
    InitVisited();
    int x,y;
    tie(x,y) = heads[idx];
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(q.empty() != true){
        int r,c;
        tie(r,c) = q.front();
        q.pop();
        team_board[r][c] = idx;
        for(int i=0; i<4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(CanGo2(nx,ny) == true){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
                team_board[nx][ny] = idx;
            }
        }
        
        
    }
}


void init(){
    for(int i=1; i<=team_cnt; i++){
        int x,y;
        tie(x,y) = heads[i];
        FindMembers(i,x,y);
        WriteTeamNum(i);
    }
}

void Move_team(int idx){
    int hx, hy,tx,ty;
    tie(hx,hy) = teams[idx].front();
    tie(tx,ty) = teams[idx].back();
    board[tx][ty] = 4; // 꼬리 빼내니까 4로 바꿔주기 
    teams[idx].pop_back();

    for(int i=0; i<4; i++){
        int nx = hx+dx[i];
        int ny = hy+dy[i];
        if(board[nx][ny] == 4){
            teams[idx].push_front(make_pair(nx,ny));
        }
    }

    int people_num = (int) teams[idx].size();
    // 각 벡터 원소들 1,2,3 board에 업데이트 하기 
    for(int i=0;i<people_num; i++){
        int x, y;
        tie(x,y) = teams[idx][i];
        if(i == 0)
            board[x][y] = 1;
        else if(i == people_num-1)
            board[x][y] = 3;
        else
            board[x][y] = 2;
    }
}

void Move(){
    // team cnt 가 모두 1칸씩 이동함
    for(int i=1; i<=team_cnt; i++){
        Move_team(i);
    }
}

tuple<int,int,int> Mapping(int idx){
    int tmp = (idx-1) / n;
    tmp %= 4;
    int r=0,c=0;

    if(tmp == 0){
        r  = idx % n;
        if(r == 0)
            r = n;
        c = 1;
    }
    else if(tmp == 1){
        r = n;
        c = idx % n;
        if(c == 0)
            c = n;
    }
    else if(tmp == 2){
        r = n - (idx % n) + 1;
        if(r == n+1)
            r = 1;
        c = n;
    }
    else if(tmp == 3){
        r = 1;
        c = n - (idx % n) + 1;
        if(c == n+1)
            c = 1;
    }
    return make_tuple(tmp,r,c);
}
pair<int,int> ThrowBall(int dir, int x, int y){
    
    int dx_ball[4] = {0,-1,0,1};
    int dy_ball[4] = {1,0,-1,0};

    if(dir == 0){
        for(int i=0; i<n; i++){
            int nx = x+dx_ball[dir]*i;
            int ny = y+dy_ball[dir]*i;
            if(board[nx][ny]>=1 && board[nx][ny] <=3){
                return make_pair(nx,ny);
            }
        }
    }
    else if(dir == 1){
        for(int i=0; i<n; i++){
            int nx = x+dx_ball[dir]*i;
            int ny = y+dy_ball[dir]*i;
            if(board[nx][ny]>=1 && board[nx][ny] <=3){
                return make_pair(nx,ny);
            }
        }
    }
    else if(dir == 2){
        for(int i=0; i<n; i++){
            int nx = x+dx_ball[dir]*i;
            int ny = y+dy_ball[dir]*i;
            if(board[nx][ny]>=1 && board[nx][ny] <=3){
                return make_pair(nx,ny);
            }
        }
    }
    else if(dir == 3){
        for(int i=0; i<n; i++){
            int nx = x+dx_ball[dir]*i;
            int ny = y+dy_ball[dir]*i;
            if(board[nx][ny]>=1 && board[nx][ny] <=3){
                return make_pair(nx,ny);
            }
        }
    }
    return make_pair(-1,-1);
}

void GetScore(int idx, int x, int y){

    int num = (int) teams[idx].size();
    int nth = -1;
    for(int i=0; i<num; i++){
        int r,c;
        tie(r,c) = teams[idx][i];
        if(r == x && c == y){
            nth = i;
            break;
        }
    }
    if(nth != -1){
        score += (nth+1)*(nth+1);
        //cout << (nth+1)*(nth+1) << endl;
    }
}

void ChangeDir(int idx){
    deque<pair<int,int> > tmp;

    int num = (int) teams[idx].size();
    for(int i=num-1; i>=0; i--){
        tmp.push_back(teams[idx][i]);
    }
    teams[idx] = tmp;

    for(int i=0; i<num; i++){
        int x, y;
        tie(x,y) = teams[idx][i];
        if(i==0){
            board[x][y] = 1;
        }
        else if(i==num-1){
            board[x][y] = 3;
        }
        else
            board[x][y] = 2;
            
    }
}

int main() {

    cin >> n >>  m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                heads[++team_cnt] = make_pair(i,j);
        }
    }

    //0. 각 팀 정보 저장하기
    init();
    //PrintTeamBoard();

    // 1. k 라운드 시작!
    for(int i=1; i<=k; i++){
        //cout <<"round : " << i << endl;
        // 1. 각 팀은 머리 사람을 따라 1칸 진행 
        Move();
        //PrintTeams();
        //PrintBoard();

        // 2. 각 라운드마다 공이 정해진 선을 따라 던져진다. 
        int d,r,c;
        tie(d,r,c) = Mapping(i); // 각 라운드마다 공이 던져지는 위치 찾기
        tie(r,c) = ThrowBall(d,r,c); // 공이 던져졌을 때 가장 먼저 맞는 사람 찾기
        //cout << r << " " << c;
        int idx = team_board[r][c]; // 공이 던져졌을 때 가장 먼저 맞는 사람의 팀 번호 찾기 
        // 2-1. 점수얻기,
        GetScore(idx, r,c);
        // 2-2. 방향 바꾸기 
        ChangeDir(idx);
        //PrintTeams();
        //PrintBoard();
    }

    cout << score;

    return 0;
}