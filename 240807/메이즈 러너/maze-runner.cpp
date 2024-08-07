#include <iostream>
#include <set>
#include <climits>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_N 11

int n,m,k; // n : 미로의 크기, m : 참가자의 수, k : 게임 시간 

int miro[MAX_N][MAX_N]; // miro 판, 빈칸 벽 표시
set<int> board[MAX_N][MAX_N]; // miro 위에 참가자 표시한 보드
int r[MAX_N]; // 참가자의 좌표. 
int c[MAX_N];
int exit_r, exit_c;
int ans = 0; // 참가자의 이동 횟수
int cur_num = 0;

// 상하좌우
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

// 미로 회전에 필요한 값. 
int sr,sc,side;

void PrintMiro(){
    cout << "miro" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << miro[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void PrintBoard(){
    cout << "board" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j].empty() == true)
                cout << 0 << " ";
            else if(board[i][j].find(-1) != board[i][j].end())
                cout << -1 << " ";
            else 
                cout << (int) board[i][j].size() << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool InRange(int x, int y){
    return x>=1 && x <=n && y >= 1&& y <=n;
}

bool CanGo(int x,int y){ // miro 범위 안에 있고, 벽이 없는지 확인 
    if(InRange(x,y) == false)
        return false;
    if(miro[x][y]  >= 1)
        return false;
    return true;
}

int CalDist(int x, int y){ // x,y 와 출구까지의 거리를 계산
    return abs(x-exit_r) + abs(y-exit_c);
}

void move(int idx){ // idx 번 참가자 이동

    int cr = r[idx];
    int cc = c[idx];
    int dist = CalDist(cr,cc); // 현재와 출구 까지의 거리를 계산
    int dir = -1;

    for(int i = 3; i>=0; i--){ // 상하가 우선이 되어야 하므로. 좌우 부터 한다. 
        int nr = cr + dx[i];
        int nc = cc + dy[i];
        if(CanGo(nr,nc) == true){
            int tmp = CalDist(nr,nc);
            if(tmp <= dist){
                dist = tmp;
                dir = i;
            }
        }
    } 
    if(dir != -1){
        board[r[idx]][c[idx]].erase(idx); // 원래 위치에서 참가자 뺌
        r[idx] += dx[dir];
        c[idx] += dy[dir]; // 한칸 이동한다. 
        board[r[idx]][c[idx]].insert(idx); // 이동한 위치에 참가자 추가 

        ans++;
        // 이동했을 때 탈출했다면? 
        if(r[idx] == exit_r && c[idx] == exit_c){
            cur_num--; // 현재 남아있는 참가자수 줄여주고,
            board[r[idx]][c[idx]].erase(idx); // 탈출했으니까 참가자 뺌. 
            r[idx] = -1; // 정보 지움. 
            c[idx] = -1;
            
        }
    }   
}


void MoveAll(){ // 모든 참가자 이동
    for(int i=1; i<=m; i++){
        if(r[i] == -1) // 이미 탈출한 참가자는 고려하지 않음 
            continue; 
        move(i);
    }
}


bool possible(int x,int y, int side){
    int cnt = 0;
    bool flag = false;
    for(int i = x; i<x+side ; i++){
        for(int j=y; j<y+side; j++){
            if(board[i][j].empty() == false && board[i][j].find(-1) == board[i][j].end() )
                cnt++; // 참가자 확인
            if(board[i][j].find(-1) != board[i][j].end())
                flag = true;
            if(cnt >= 1 && flag == true){
                return true;
            }
        }
    }
    return false;
}

void find_min_side(){ // 참가자와 출구로 만들 수 있는 가장 작은 변 찾기 sr,sc 도 업데이트

    side = INT_MAX;

    for(int i=1; i<=m; i++){
        if(r[i] == -1)
            continue;
        int tmp = max(abs(r[i]-exit_r)+1, abs(c[i]-exit_c)+1);
        side = min(tmp,side);
    }

    
    for(int x = 1; x<=n; x++){
        for(int y = 1;y<=n; y++){
            if(x + side > n || y + side > n)
                continue;
            if(possible(x,y,side)){
                sr = x;
                sc = y;
                return;
            }
        }
    }
}

void rotation(){

    //cout << "rotation : " << side << endl;

    int tmp_miro[side][side];
    set<int> tmp_board[side][side];

    // miro, board를 90도 회전한 값 tmp에 저장함
    for(int i = sr; i < sr + side; i++){
        for(int j = sc; j < sc + side; j++){
            tmp_miro[j-sc][side-1-(i-sr)] = miro[i][j]; 
            tmp_board[j-sc][side-1-(i-sr)] = board[i][j]; 
        }
    }
    
    // 저장한 걸로 업데이트 함. 
    for(int i = sr; i < sr + side; i++){
        for(int j = sc; j < sc + side; j++){
            miro[i][j] = tmp_miro[i-sr][j-sc];
            board[i][j]= tmp_board[i-sr][j-sc];
        }
    }
    
    for(int i = sr; i < sr + side; i++){
        for(int j = sc; j < sc + side; j++){
            if(miro[i][j] >= 1){
                miro[i][j]--; // 벽은 회전했으므로, 1씩 내구성 감소. 
            }
            if(board[i][j].find(-1) != board[i][j].end()){ // 회전된 탈출구 업데이트 
                exit_r = i;
                exit_c = j;
            }
            if(board[i][j].empty() == false && board[i][j].find(-1) == board[i][j].end()){
                set<int>::iterator it;
                for(it = board[i][j].begin(); it != board[i][j].end(); it++){
                    int idx = *it;
                    r[idx] = i; c[idx] = j;
                }
            }

        }
    }

}

void PrintMan(){
    for(int i=1; i<=m; i++){
        cout <<"i : r,c "<<i <<" " <<r[i] << " " <<c[i] << endl;
    }
}
int main() {
    
    cin >> n >> m >> k;
    cur_num = m; // 현재 남아있는 참가자의 수.

    for(int i=1; i<=n;i++){
        for(int j=1; j<=n; j++){
            cin >> miro[i][j];
        }
    }

    for(int i=1; i<=m; i++){
        cin >> r[i] >> c[i];
        board[r[i]][c[i]].insert(i); // 보드 위에 참가자 표현 아 근데.. 참가자가... 여러명 가능하다고 했잖아. 
    }

    cin >> exit_r >> exit_c;
    board[exit_r][exit_c].insert(-1);
    miro[exit_r][exit_c] = -1;
    
    for(int i=1; i<=k; i++){

        
        // 모든 참가자 이동.
        MoveAll(); 

        // 모든 참가자가 탈출했다면 종료하는 조건.
        if(cur_num == 0) 
            break;

        // 미로 회전.
        // 1. 출구에서 가장 가까운 참가자 찾기 : 거리는 만들 수 있는 정사각형의 변이 가장 작은 것
        // 2. 정사각형의 sc, min_c, 변의 길이 계산하기 
        find_min_side();

        // 3. 90도 회전하기 
        // 4. 각 벽 -1 하기! 벽의 값이 1 이상이라면 1씩 감소. 
        // 5. 각 참가자들의 위치 값 update 하기. 
        rotation();

    }

    // 정답 출력
    cout << ans << endl;
    cout << exit_r << " " <<exit_c << endl;
    

    return 0;
}