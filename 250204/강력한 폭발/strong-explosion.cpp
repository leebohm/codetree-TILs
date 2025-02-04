#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_N 21

int n;
int board[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
int sz; // pos의 개수 
vector<int> options;
vector<pair<int,int> > pos;
int ans= 0;

int dx1[4] = {-1,-2,1,2};
int dy1[4] = {0,0,0,0};
int dx2[4] = {-1,0,1,0};
int dy2[4] = {0,-1,0,1};
int dx3[4] = {-1,-1,1,1};
int dy3[4] = {-1,1,-1,1};

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

bool InRange(int x, int y){
    return x>=0 && x < n && y >=0 && y < n;
}

void Bomb(int opt, int x, int y){
    board[x][y] = -1;
    if(opt == 1){
        for(int i=0; i<4; i++){
            int nx = x+dx1[i];
            int ny = y+dy1[i];
            if(InRange(nx,ny) == true)
                board[nx][ny] = -1;
        }
    }
    if(opt == 2){
        for(int i=0; i<4; i++){
            int nx = x+dx2[i];
            int ny = y+dy2[i];
            if(InRange(nx,ny) == true)
                board[nx][ny] = -1;
        }
    }
    if(opt == 3){
        for(int i=0; i<4; i++){
            int nx = x+dx3[i];
            int ny = y+dy3[i];
            if(InRange(nx,ny) == true)
                board[nx][ny] = -1;
        }
    }
}

int Count(){
    init();
    for(int i=0; i<sz; i++){
        int x,y;
        tie(x,y) = pos[i];
        Bomb(options[i],x,y);
    }
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0;j<n; j++)
            if(board[i][j]==-1)
                cnt++;
    return cnt;
}

void Backtracking(int num){
    if(num == sz){
        ans = max(ans, Count());
        return;
    }

    for(int i=1; i<=3; i++){
        options.push_back(i);
        Backtracking(num+1);
        options.pop_back();
    }
}

int main() {
    
    cin >> n;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            tmp[i][j] = board[i][j];
            if(board[i][j] == 1)
                pos.push_back(make_pair(i,j));

        }
    }
    sz = pos.size();

    Backtracking(0);

    cout << ans;
    return 0;
}