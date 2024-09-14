#include <iostream>
#include <set>
using namespace std;

#define MAX_N 21

int n, m, k, c; // n : 격자의 크기, m : 박멸이 진행되는 년 수, k : 제초제의 확산 범위, c : 제초제가 남아있는 년 수
int board[MAX_N][MAX_N];
int tmp_board[MAX_N][MAX_N];
int killer[MAX_N][MAX_N];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dx_diagonal[4] = {-1,-1,1,1};
int dy_diagonal[4] = {-1,1,-1,1};
int ans = 0;

void InitTempBoard(){
    for(int i=0; i<n;i++)
        for(int j=0;j<n; j++)
            tmp_board[i][j] = 0;
}

void PrintBoard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool InRange(int x, int y){
    return x>=0 &&  x < n && y >= 0 && y < n;
}

int CountNextTree(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny) == true && board[nx][ny] > 0){
            cnt++;
        }
    }
    return cnt;
}

void Grow(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]>0){// 나무가 있다면 ?
                int cnt =  CountNextTree(i,j);
                board[i][j] += cnt;
            }
        }
    }
}

int CountAvailable(int x, int y, int t){
    int cnt = 0;
    for(int i = 0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        // 범위 안에 있고, 주변에 나무가 없고, 제초제가 없는 경우 
        if(InRange(nx,ny) && board[nx][ny] == 0 && killer[nx][ny] < t)
            cnt++;
    }
    return cnt;
}

void GenerateNewTree(int x, int y, int t, int new_tree){
    for(int i = 0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        // 범위 안에 있고, 주변에 나무가 없고, 제초제가 없는 경우 
        if(InRange(nx,ny) && board[nx][ny] == 0 && killer[nx][ny] < t)
            tmp_board[nx][ny] += new_tree;
    }
}
void Exe_TempBoard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 0)
                board[i][j] += tmp_board[i][j];
        }
    }
}
void Breed(int t){
    InitTempBoard();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] > 0){
                int cnt = CountAvailable(i,j,t);
                if(cnt > 0){
                    int new_tree = board[i][j] / cnt;
                    GenerateNewTree(i,j,t,new_tree);
                }
            }
        }
    }
    Exe_TempBoard();
}

int CountKilledTree(int x, int y){
    set<int> BadDirection;
    int cnt = 0;
    cnt += board[x][y];
    for(int v = 1; v <= k; v++){
        for(int i=0; i<4; i++){
            if(BadDirection.find(i) == BadDirection.end()){
                int nx = x + dx_diagonal[i] * v;
                int ny = y + dy_diagonal[i] * v;
                if(InRange(nx,ny) && board[nx][ny] == -1){
                    BadDirection.insert(i);
                }
                if(InRange(nx,ny) && board[nx][ny] != -1){
                    cnt += board[nx][ny];
                }
            }
        }
    }

    return cnt; 
}

void KillTree(int x, int y, int t){
    set<int> BadDirection;
    // 대각선 k 범위 이내 외에도 가운데에도 0으로 만들기. 
    board[x][y] = 0;
    killer[x][y] = t+c;
    for(int v = 1; v <= k; v++){
        for(int i=0; i<4; i++){
            if(BadDirection.find(i) == BadDirection.end()){
                int nx = x + dx_diagonal[i] * v;
                int ny = y + dy_diagonal[i] * v;
                if(InRange(nx,ny) && board[nx][ny] == -1){
                    BadDirection.insert(i);
                }
                if(InRange(nx,ny) && board[nx][ny] != -1){
                    board[nx][ny] = 0;
                    killer[nx][ny] = t+c;
                }
            }
            
        }
    }
}

void Sprinkle(int t){
    // 1. 제초제 뿌렸을 경우 나무가 가장 많이 죽는 위치를 찾기 
    int pi,pj;

    int max_cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 조건 : 나무가 있는 칸에만 뿌릴 수 있음 
            if(board[i][j] > 0){
                int cnt = CountKilledTree(i,j);
                if(max_cnt < cnt){
                    pi = i;
                    pj = j;
                    max_cnt = cnt;
                }
            }
        }
    }
    // 2. 제초제 뿌리기
    // 죽게되는 나무들 다 죽이기
    ans += max_cnt;
    //cout << "pi, pj : " << pi << " " << pj  << " "  << max_cnt << endl;
    if(max_cnt != 0)
        KillTree(pi,pj,t);

}

int main() {
    
    cin >> n >> m >> k >> c;

    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cin >> board[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        // 1. 나무의 성장 
        Grow();
        // 2. 나무의 번식
        Breed(i);
        // 3. 제초제 뿌리기
        Sprinkle(i);  
    }
    cout << ans;

    return 0;
}