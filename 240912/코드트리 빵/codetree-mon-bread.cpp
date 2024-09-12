#include <iostream>
#include <tuple>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define MAX_N 16
#define MAX_M 226

int n,m; // n : 격자의 크기, m : 사람의 수 
int board[MAX_N][MAX_N]; // 베이스캠프 위치 담기 
bool bool_board[MAX_N][MAX_N]; // 방문한 베이스캠프, 편의점 -> false로 저장
int visited[MAX_N][MAX_N]; // BFS에 사용할 것
pair<int,int> people_pos[MAX_M];
pair<int,int> con_pos[MAX_M]; // 편의점 위치
pair<int,int> base_pos[MAX_M]; // 베이스 캠프 위치 
int base_num = 0; // 베이스 캠프 개수
int cnt_m = 0; // 방문 완료한 편의점 개수
vector<int> arrived_con; // 편의점에 도착한 사람 번호 

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void InitVisited(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = 0;
        }
    }
}

bool InRange(int x, int y){
    return x >=1 && x<=n && y >= 1 && y <= n;
}

bool CanGo(int x, int y){
    if(bool_board[x][y] == false)
        return false;
    if(InRange(x,y) == false)
        return false;
    return true;
}

void PrintVisited(){
    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=n; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}
void BFS(int x, int y){

    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(q.empty() != true){
        int tx,ty;
        tie(tx,ty) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = tx+dx[i];
            int ny = ty+dy[i];
            if(CanGo(nx,ny) == true && visited[nx][ny] == 0){
                visited[nx][ny] = visited[tx][ty]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    
}

void act1(){
    arrived_con.clear();
    // 1. i번 사람이 가고 싶은 편의점 방향을 향해서 1칸 움직이기
    for(int i=1; i<=m; i++){
        int x,y;
        tie(x,y) = people_pos[i];
        int cx,cy;
        tie(cx,cy) = con_pos[i];
        if(x == 0)
            continue;
        // BFS로 가장 가까워지는 거리의 방향을 구하기
        priority_queue<pair<int,int>> pq; // 최단거리랑 방향 인덱스 번호 정보 음수로 담기. 그래야 최솟값 우선되니까
        for(int j=0; j<4; j++){
            int nx = x+dx[j];
            int ny = y+dy[j];
            if(CanGo(nx,ny) == true){
                InitVisited();
                visited[nx][ny] = 1;
                BFS(nx,ny);
                if(visited[cx][cy] != 0)
                    pq.push(make_pair(-visited[cx][cy],-j));
            }
        }
        int dir;
        tie(ignore,dir) = pq.top();
        dir = -dir;
        x += dx[dir];
        y += dy[dir];
        people_pos[i] = make_pair(x,y);

        // 1-2. 편의점에 도착한 경우 
        if(x == cx && y == cy){
            people_pos[i] = make_pair(0,0); // 이 사람은 이동하지 않아도 됨
            arrived_con.push_back(i);
        }
    }


}

void act2(){
    // 2. 편의점에 도착한 사람들 번호를 이용해 도착한 편의점 이동 불가하게 만들기
    int num = (int) arrived_con.size();
    for(int i=0; i<num; i++){
        int cx,cy;
        tie(cx,cy) = con_pos[arrived_con[i]];
        bool_board[cx][cy] = false;
        cnt_m++;
    }
}

void act3(int t){
    // 3. 가고 싶은 편의점과 가장 가까운 베이스 캠프 찾기 
    int cx,cy;
    tie(cx,cy) = con_pos[t];

    priority_queue<tuple<int,int,int,int>> pq; // 거리, 행, 열, index 정보 적기
    for(int i=0; i<base_num; i++){
        int bx,by;
        tie(bx,by) = base_pos[i];
        if(bx == 0 || by == 0)
            continue;
        InitVisited();
        visited[bx][by] = 1;
        BFS(bx,by);
        if(visited[cx][cy] != 0)
            pq.push(make_tuple(-visited[cx][cy],-bx,-by,i));
    }
    int px,py,idx;
    tie(ignore, px,py,idx) = pq.top();
    px = -px; py = -py; 
    people_pos[t] = make_pair(px,py);
    bool_board[px][py] = false;
    base_pos[idx] = make_pair(0,0);
}

void Print_people_pos(){
    for(int i=1;i<=m; i++){
        cout << i << " : " << people_pos[i].first << " " << people_pos[i].second << endl;
    }
}

int main() {

    cin >> n >> m;
    int t = 1;

    for(int i=1; i<=n; i++){
        for(int j=1;j<=n; j++){
            cin >> board[i][j];
            bool_board[i][j] = true;
            if(board[i][j] == 1){
                base_pos[base_num++] = make_pair(i,j);

            }
        }
    }

    for(int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        con_pos[i] = make_pair(x,y);
        people_pos[i] = make_pair(0,0);
    }

    while(t!=0){
        act1();
        act2();
        if(t <= m)
            act3(t);
        if(cnt_m == m)
            break;
        //cout << t << endl;
        //Print_people_pos();
        t++;
    }
    
    cout << t; 
    return 0;
}
// 출력 : 총 몇분 후에 모두 편의점에 도착하는 지