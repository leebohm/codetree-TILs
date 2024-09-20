#include <iostream>
#include <tuple>
#include <vector>
#include <set>

using namespace std;
#define MAX_N 100
#define MAX_M 10000

int n,m,h,k; // n*n 격자의 크기, m 명의 도망자, h 개의 나무, k번의 턴 
// 모든 위치 1부터 시작함. 
bool TreePos[MAX_N][MAX_N]; // 나무 있는 곳은 true
set<int> board[MAX_N][MAX_N]; // 그 보드에 있는 도망자의 index를 기록하기 
// 좌우 하상
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int dir_info[MAX_M]; // 각 idx 번째 도망자의 방향을 기록. 
pair<int,int> runner_pos[MAX_M]; // 각 Idx 번째 도망자의 위치를 기록.
int tx = 0;
int ty = 0;
int td = 3;
int tag_dir1[MAX_N][MAX_N];
int tag_dir2[MAX_N][MAX_N];
int opt = 1;

// 위 오 아 왼
int dx_t[4] = {-1,0,1,0};
int dy_t[4] = {0,1,0,-1};

int score = 0;

int ChangeDir(int d){
    if(d == 0)
        return 1;
    else if(d == 1)
        return 0;
    else if(d == 2)
        return 3;
    else if(d == 3)
        return 2;
}


void PrintDir(){
    for(int i=1; i<=m;i++)
        cout << dir_info[i] << " ";
    cout << endl;
}

void PrintPos(){
    for(int i=1; i<=m; i++){
        cout << i << "의 pos " << runner_pos[i].first << " " << runner_pos[i].second << endl;
    }
    cout << endl;
}

void PrintTagDir1(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << tag_dir1[i][j] << " "; 
        }
        cout << endl;
    }
}
void PrintTagDir2(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << tag_dir2[i][j] << " "; 
        }
        cout << endl;
    }
}
void PrintBoard(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int num = (int) board[i][j].size();
            if(num == 0)
                cout << 0 << " ";
            else{
                set<int>::iterator it;
                for(it = board[i][j].begin(); it != board[i][j].end(); it++){
                    cout << *it << " ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool InRange(int x, int y){
    return x >=1 && x <=n && y>=1 && y<=n;
}

void Update(int x, int y, int dir, int idx){
    dir_info[idx] = dir;
    runner_pos[idx] = make_pair(x,y);
    board[x][y].insert(idx);
}

int CalDist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}
void MoveRunner(){
    // 각 도망자 이동.
    for(int i=1; i<=m; i++){
        int x,y;
        tie(x,y) = runner_pos[i];
        if(x== -1 && y==-1)
            continue;
        int dist = CalDist(x,y, tx,ty);
        if(dist > 3)    
            continue;
        int d = dir_info[i];
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(InRange(nx,ny) == true){
            if(nx == tx && ny == ty){
                // 술래가 있으면 이동하지 않음 
                continue;
            }
            else{
                board[x][y].erase(i);
                x = nx; y = ny;
                
            }
        }
        else{
            // 격자 밖으로 벗어난다면? 
            int dir = ChangeDir(d);
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx == tx && ny == ty){
                continue; // 술래가 있으면 이동하지 않음
            }
            else{
                board[x][y].erase(i);
                x = nx; y = ny; d = dir;
            }

        }
        Update(x,y,d,i);
    }
}



void InitTagDir(){
    
    int cx = n/2+1, cy = n/2+1;

    int cdir = 0;

    for(int j=1;j<=n-1;j++){
        for(int i=0; i<2; i++){
            for(int p = 0; p <j; p++){
                tag_dir1[cx][cy] = cdir;
                cx += dx_t[cdir];
                cy += dy_t[cdir];
            }
            cdir++;
            cdir %= 4;
        }
    }     
    tag_dir1[1][1] = 2;
    for(int i=1; i<=n-1; i++)
        tag_dir2[i][1] = 2;
    cx = n, cy = 1, cdir = 1;
    for(int j=n-1;j>=1;j--){
        for(int i=0; i<2; i++){
            for(int p = 0; p <j; p++){
                tag_dir2[cx][cy] = cdir;
                cx += dx_t[cdir];
                cy += dy_t[cdir];
            }
            cdir += 3;
            cdir %= 4;
        }
    }
}

void EraseRunner(int x, int y){
    // x, y 위치에 있는 runner 지워주기
    set<int>::iterator it;
    for(it = board[x][y].begin(); it != board[x][y].end(); it++){
        int idx = *it;
        runner_pos[idx] = make_pair(-1,-1);
    }
    board[x][y].clear();
}

void MoveTagger(int t){
    // 1. 현재 opt 확인한후 Tag_dir 보드판을 이용해 넥스트 위치 찾아주기 
    int nx,ny;
    if(opt == 1){
        nx = tx + dx_t[tag_dir1[tx][ty]];
        ny = ty + dy_t[tag_dir1[tx][ty]];
    }
    else{
        nx = tx + dx_t[tag_dir2[tx][ty]];
        ny = ty + dy_t[tag_dir2[tx][ty]];
    }
    tx = nx;
    ty = ny;
    // opt 바꿔주는 위치 설정하기 
    if(tx == 1 && ty == 1)
        opt = 2;
    else if(tx == n/2+1 && ty == n/2+1)
        opt = 1;
    
    // 2. 보이는 방향으로부터 3칸 거리에 있는 곳에 도망자 있는지 확인하기. 
    int dir = 0;
    if(opt == 1)
        dir = tag_dir1[tx][ty];
    else if(opt == 2)
        dir = tag_dir2[tx][ty];

    for(int i=0; i<3; i++){
        nx = tx + dx_t[dir] * i;
        ny = ty + dy_t[dir] * i;
        if(TreePos[nx][ny] == false){
            int num = (int) board[nx][ny].size();
            if(num > 0){
                score += (t * num);
                EraseRunner(nx,ny);
            }
        }
    }
    
    return;
}


int main() {

    cin >> n >> m >> h >> k;

    for(int i=1; i<=m; i++){
        // 도망자의 위치, 방향 입력받기 
        // d = 1 : 좌우로만 움직임
        // d = 2 : 상하로만 움직임
        int x,y,d;
        cin >> x >> y >> d;
        board[x][y].insert(i);
        runner_pos[i] = make_pair(x,y);
        dir_info[i] = d;
    }

    for(int i=0; i<h; i++){
        // 나무의 위치 입력받기 
        int x,y;
        cin >> x >> y; 
        TreePos[x][y] = true;
    }

    tx = n/2+1, ty = n/2+1;

    InitTagDir();

    for(int t = 1; t<=k; t++){
        // k번의 턴을 돌기 
        // 1. 도망자 이동
        MoveRunner();
        // 2. 술래 이동
        MoveTagger(t);
    }

    cout << score;

    return 0;
}