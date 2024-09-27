#include <iostream>
#include <tuple>
#include <vector>
#include <map>

#define MAX_N 21

using namespace std;

// 왼, 위, 오른, 아래
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
vector<tuple<int,int,int>> AC_pos;

int AC_board[MAX_N][MAX_N];
int tmp_board[MAX_N][MAX_N];
map<tuple<int,int>,tuple<int,int,int>> walls;
int n,m,k; // n : 격자 변 크기, m : 벽의 개수, k : 사무실이 원하는 시원함의 정도 
bool WorkPlace[MAX_N][MAX_N]; // 사무실의 위치

void PrintTmpBoard(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << tmp_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void PrintACBoard(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << AC_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initTmpBoard(){
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n;j++){
            tmp_board[i][j] = 0;
        }
    }
}

bool InRange(int x, int y){
    return x >= 1 && x <=n && y >= 1 &&  y<=n;
}

bool Check(int ox, int oy, int x, int y){
    
    int tx,ty,ts;
    if(walls.find(make_tuple(ox,oy)) != walls.end()){
        tie(tx,ty,ts) = walls[make_tuple(ox,oy)];
        if(tx == x && ty == y)
            return false;
    }
    
    if(walls.find(make_tuple(x,y)) != walls.end()){
        tie(tx,ty,ts) = walls[make_tuple(x,y)];
        if(tx == ox && ty == oy)
            return false;
    }
    
    return true;
}

void ColdWave(int val, int ox, int oy, int x, int y, int d){
    if(InRange(x,y) == false)
        return;
    if(val == 1)
        return;
    
    bool flag = Check(ox,oy,x,y);
    if(flag == true){
        tmp_board[x][y] = val;
            
        int nx,ny;
        nx = x + dx[d];
        ny = y + dy[d];

    // 왼, 위, 오른, 아래
        if(d == 1 || d == 3 ){
            flag = Check(x,y,x,y-1);
            if(flag == true)
                ColdWave(val-1, x,y-1,nx,ny-1,d);

            ColdWave(val-1, x,y,nx,ny,d);

            flag = Check(x,y,x,y+1);
            if(flag == true)
                ColdWave(val-1, x,y+1,nx,ny+1,d);
        }
        else if(d == 0 || d == 2){
            flag = Check(x,y,x-1,y);
            if(flag == true)
                ColdWave(val-1, x-1,y,nx-1,ny,d);

            ColdWave(val-1, x,y,nx,ny,d);

            flag = Check(x,y,x+1,y);
            if(flag == true)
                ColdWave(val-1, x+1,y,nx+1, ny,d);
        }
    }
  
}

void AC_turn_on(int idx){
    
    int x,y,d;
    tie(x,y,d) = AC_pos[idx];

    int nx = x+dx[d];
    int ny = y+dy[d];

    ColdWave(5,x,y,nx,ny,d);

}

void Add_tmp_to_board(){
    for(int i=1;i<=n; i++)
        for(int j=1; j<=n; j++)
            AC_board[i][j] += tmp_board[i][j];
}

void Mix(){
    // 오른쪽, 아래
    int dx2[2] = {0,1};
    int dy2[2] = {1,0};
    
    for(int i=1; i<=n; i++){
        for(int j=1;j <=n; j++){
            for(int h = 0; h < 2; h++){
                int ni = i + dx2[h];
                int nj = j + dy2[h];
                if(InRange(ni,nj) == false)
                    continue;
                bool flag = Check(i,j,ni,nj);
                if(flag == true){
                    int diff = abs(AC_board[i][j] - AC_board[ni][nj]) / 4;
                    if(diff > 0){
                        if(AC_board[i][j] > AC_board[ni][nj]){
                            tmp_board[i][j] -= diff;
                            tmp_board[ni][nj] += diff;
                        }
                        else{
                            tmp_board[i][j] += diff;
                            tmp_board[ni][nj] -= diff;
                        }
                    }
                }  
            }
            
        }
    }
}

void Outside(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 || i == n || j==1 || j== n){
                if(AC_board[i][j] != 0)
                    AC_board[i][j] -= 1;
            }
                
        }
    }
}
void Simulation(){
    int ac_num = (int) AC_pos.size();
    for(int i=0; i < ac_num; i++){
        initTmpBoard();
        AC_turn_on(i);
        Add_tmp_to_board();
    }
        initTmpBoard();
        Mix();
        Add_tmp_to_board();
        Outside();
}

bool Count(){
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(WorkPlace[i][j] == true){
                if(AC_board[i][j] < k)
                    return false;
            }
                
        }
    }
    return true;
}

int main() {

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int tmp = 0;
            cin >> tmp;
            if(tmp == 1)
                WorkPlace[i][j] = true;
            else if(tmp >= 2){
                AC_pos.push_back(make_tuple(i,j,tmp-2));
            }
        }
    }
    
    for(int i=0; i<m; i++){
        int x,y,s;
        cin >> x >> y >> s;
        if(s == 0){
            walls[make_tuple(x,y)] = make_tuple(x-1, y,s);
            walls[make_tuple(x-1,y)] = make_tuple(x,y,s);
        }
        else if(s == 1){
            walls[make_tuple(x,y)] = make_tuple(x,y-1,s);
            walls[make_tuple(x,y-1)] = make_tuple(x,y,s);
        }
    }
    int ans = 0;
    while(true){
        Simulation();
        ans++;
        bool flag = Count();
        if(flag == true)
            break;
    }
    cout << ans;

    return 0;
}