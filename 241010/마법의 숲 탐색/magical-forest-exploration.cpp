#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;

#define MAX_RC 75
#define MAX_K 1001

int r,c,k;
int board[2*MAX_RC][MAX_RC]; // 숲
int exits[MAX_K]; // 각 골렘의 출구
int G_MaxR[MAX_K]; // 각 정령의 최대 행 기록
int ans = 0; // 정답 최대행 누적
pair<int,int> points[MAX_K]; // 시작 위치
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool InRange(int x, int y){
    return x>=1 && x <=2*r && y>=1 && y <=c;
}
bool MoveSouth(int cx, int cy, int idx){
    vector<pair<int,int> > G;
            G.push_back(make_pair(cx,cy-1));
            G.push_back(make_pair(cx+1,cy));
            G.push_back(make_pair(cx,cy+1));
        bool flag = true;
        for(int i=0; i<(int)G.size(); i++){
            int x,y;
            tie(x,y) = G[i];
            int nx = x+1; int ny = y;
            if(InRange(nx,ny) == false){
                flag = false;
                return flag;
            }
            if(board[nx][ny] > 0){
                flag = false;
                return flag;
            }
        }
        if(flag == true){
            points[idx] = make_pair(cx+1,cy);
        }
    return flag;
}

bool MoveWest(int cx, int cy, int idx){
    vector<pair<int,int> > G;
        G.push_back(make_pair(cx-1,cy));
        G.push_back(make_pair(cx,cy-1));
        G.push_back(make_pair(cx+1,cy));
    bool flag = true;
    for(int i=0; i<(int)G.size(); i++){
        int x,y;
        tie(x,y) = G[i];
        int nx = x; int ny = y-1;
        if(InRange(nx,ny) == false){
            flag = false;
            return flag;
        }
        if(board[nx][ny] > 0){
            flag = false;
            return flag;
        }
    }
    if(flag == true){ 
        int ncx = cx;
        int ncy = cy - 1;
        G.clear();
        G.push_back(make_pair(ncx,ncy-1));
        G.push_back(make_pair(ncx+1,ncy));
        G.push_back(make_pair(ncx,ncy+1));
        for(int i=0; i<(int) G.size(); i++){
            int x, y;
            tie(x,y) = G[i];
            int nx = x+1; int ny = y;
            if(InRange(nx,ny) == false){
                flag = false;
                return flag;
            }
            if(board[nx][ny] > 0){
                flag = false;
                return flag;
            }
        }
        if(flag == true){
            points[idx] = make_pair(cx+1, cy-1);
            int d = exits[idx];
            if(d-1 == -1)
                exits[idx] = 3;
            else
                exits[idx] = d-1;
        }
    }
    return flag;
}


bool MoveEast(int cx, int cy, int idx){
    vector<pair<int,int> > G;
    G.push_back(make_pair(cx-1,cy));
    G.push_back(make_pair(cx,cy+1));
    G.push_back(make_pair(cx+1,cy));
    bool flag = true;
    for(int i=0; i<(int) G.size(); i++){
        int x,y;
        tie(x,y) = G[i];
        int nx = x; int ny = y+1;
        if(InRange(nx,ny) == false){
            flag = false;
            return flag;
        }
        if(board[nx][ny] > 0){
            flag = false;
            break;
        }
    }
    if(flag == true){ 
        int ncx = cx; int ncy = cy+1;
        G.clear();
        G.push_back(make_pair(ncx,ncy-1));
        G.push_back(make_pair(ncx+1,ncy));
        G.push_back(make_pair(ncx,ncy+1));
        for(int i=0; i<(int)G.size(); i++){
            int x, y;
            tie(x,y) = G[i];
            int nx = x+1; int ny = y;
            if(InRange(nx,ny) == false){
                flag = false;
                return flag;
            }
            if(board[nx][ny] > 0){
                flag = false;
                break;
            }
        }
        if(flag == true){
            points[idx] = make_pair(cx+1, cy+1);
            int d = exits[idx];
            if(d+1 == 4)
                exits[idx] = 0;
            else
                exits[idx] = d+1;
        }
    }
    return flag;
}

int MoveG(int idx){
    int cnt = 0;
    while(true){
        int cx,cy;
        tie(cx,cy) = points[idx];
        // 1. 남쪽으로 이동 
        bool flag = MoveSouth(cx,cy,idx);
        if(flag == true){
            cnt++;
            continue;
        }
        
        // 2. 서쪽으로 한칸 이동, 남쪽으로 한칸 이동
        flag = MoveWest(cx,cy,idx);
        if(flag == true){
            cnt++;
            continue;
        }
        // 3. 동쪽으로 한칸 이동, 남쪽으로 한칸 이동
        flag = MoveEast(cx,cy,idx);
        if(flag == false)
            break;
        else
            cnt++;
    }
    return cnt;
}

void Reset(){
    for(int i=1; i<=2*r; i++){
        for(int j=1; j<=c; j++){
            board[i][j] = 0;
        }
    }
    for(int i=1; i<=k; i++)
        G_MaxR[i] = 0;
}

void PrintBoard(){
    for(int i=r+1; i<=2*r; i++){
        for(int j=1; j<=c; j++){
            cout << setw(3) << setfill('0') << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
priority_queue<pair<int,int> > FindOtherG(int ex,int ey, int idx){
    priority_queue<pair<int,int> > pq;
    int cx,cy;
    tie(cx,cy) = points[idx];
    pq.push(make_pair(cx+1,idx));
    for(int i=0; i<4; i++){
        int nx = ex+dx[i];
        int ny = ey+dy[i];
        if(InRange(nx,ny) == true){
            if(board[nx][ny] != 0 && board[nx][ny]!= idx){
                int other_idx = board[nx][ny];
                pq.push(make_pair(G_MaxR[other_idx],other_idx));
            }
        }
    }
    return pq;
}
bool IsExit(int x, int y, int idx){
    int cx,cy;
    tie(cx,cy) = points[idx];
    int d = exits[idx];
    int ex = cx + dx[d];
    int ey = cy + dy[d];
    if(ex == x && ey == y)
        return true;
    return false;
}

void Update(int ex, int ey, int idx, int max_r){
    for(int i=0; i<4; i++){
        int nx = ex + dx[i];
        int ny = ey + dy[i];
        if(InRange(nx,ny) == true && board[nx][ny] != 0){
            int nidx = board[nx][ny];
            if(nidx!= idx && IsExit(nx,ny,nidx)){
                if(G_MaxR[nidx] < max_r){
                    G_MaxR[nidx] = max_r;
                    Update(nx,ny,nidx,max_r);
                }

            }
        }
    }
}

void MoveAngel(int idx){
    int d = exits[idx];
    int cx,cy;
    tie(cx,cy) = points[idx];
    int ex = cx + dx[d];
    int ey = cy + dy[d];
    priority_queue<pair<int,int> > pq;
    pq = FindOtherG(ex,ey,idx);
    if((int) pq.size() == 1)
        G_MaxR[idx] = cx+1;
    else{
        int max_r, index;
        tie(max_r, index) = pq.top(); pq.pop();
        G_MaxR[idx] = max_r;
        Update(ex,ey,idx,max_r);
    }
    if(G_MaxR[idx] > r)
        ans += (G_MaxR[idx]-r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> k;

    for(int i=1; i<=k; i++){
        int cy, d;
        cin >> cy >> d;
        points[i] = make_pair(1,cy);
        exits[i] = d;
    }

    for(int i=1; i<=k; i++){
        int check = MoveG(i);
        if(points[i].first < 2+r || check == 0){
            Reset();
            continue;
        }
        int cx = 0;
        int cy = 0;
        tie(cx,cy) = points[i];
        board[cx][cy] = i;
        for(int j=0; j<4; j++){
            int nx = cx+dx[j];
            int ny = cy+dy[j];
            board[nx][ny] = i;
        }
        MoveAngel(i);
        //PrintBoard();
    }
    cout << ans <<"\n";
    return 0;
}