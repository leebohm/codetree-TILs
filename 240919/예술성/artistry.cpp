#include <iostream>
#include <set>
#include <tuple>
using namespace std;

#define MAX_N 29
#define MAX_G 900
int n; 
int board[MAX_N][MAX_N];
int score = 0;
int groups_num[MAX_G]; // index : 그룹번호, value : 그룹에 속한 칸의 수 
int groups_val[MAX_G];
int group_board[MAX_N][MAX_N]; // 각 위치에 그룹 번호 표시하기 
bool visited[MAX_N][MAX_N];
set<pair<int,int>> group_pair;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool InRange(int x, int y){
    return x >= 0 && x < n  && y >= 0 && y < n;
}

bool CanGo(int x, int y, int num){
    if(InRange(x,y) == false)
        return false;
    if(num != board[x][y])
        return false;
    if(visited[x][y] == true)
        return false;
    return true;
}

void DFS(int x, int y, int num, int idx){
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(CanGo(nx,ny,num) == true){
            visited[nx][ny] = true;
            group_board[nx][ny] = idx;
            DFS(nx,ny,num,idx);
        }
    }
}

void InitVisited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }
}

int Grouping(){
    InitVisited();
    int idx = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false){
                visited[i][j] = true;
                group_board[i][j] = idx;
                DFS(i,j, board[i][j],idx);
                idx++;
            }
        }
    }
    return idx-1;
}
void CountGroupnum(int num){
    for(int t=1; t<=num; t++){
        int cnt = 0;
        for(int x = 0; x< n; x++){
            for(int y= 0; y<n; y++){
                if(t == group_board[x][y]){
                    cnt++;
                    groups_val[t] = board[x][y];
                }
            }
        }
        groups_num[t] = cnt;
        
    }
}

void FindGroupPair(){
    group_pair.clear();

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(group_board[i][j] != group_board[i][j+1]){
                int idx_min = min(group_board[i][j], group_board[i][j+1]);
                int idx_max = max(group_board[i][j], group_board[i][j+1]);
                group_pair.insert(make_pair(idx_min, idx_max));
            }
        }
    }
            
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(group_board[i][j] != group_board[i+1][j]){
                int idx_min = min(group_board[i][j], group_board[i+1][j]);
                int idx_max = max(group_board[i][j], group_board[i+1][j]);
                group_pair.insert(make_pair(idx_min, idx_max));
            }
        }
    }
}
int CntSideNum(int x, int y){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(group_board[i][j] != group_board[i][j+1] && 
            ((group_board[i][j] == x && group_board[i][j+1] == y) ||
            (group_board[i][j] == y && group_board[i][j+1] == x))){
                cnt++;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(group_board[i][j] != group_board[i+1][j] && 
            ((group_board[i][j] == x && group_board[i+1][j] == y) ||
            (group_board[i][j] == y && group_board[i+1][j] == x))){
                cnt++;
            }
        }
    }

    return cnt;
}

int CalScore(int x, int y){
    int score = 0;
    // 그룹 x와 그룹 y의 조화로움
    // (그룹 x에 속한 칸의 수 + 그룹 y에 속한 칸의 수) * 그룹 x를 이루고 있는 숫자값 * 그룹 y를 이루고 있는 숫자 값 * 그룹x,y가 서로 맞닿아 있는 변의 수
    int tmp = CntSideNum(x,y);
    score = (groups_num[x] + groups_num[y]) * groups_val[x] * groups_val[y] * tmp;
    return score;
}


int GetInitScore(){
    // 1. 그룹화하기 
    int num = Grouping();
    // 2. 각 그룹에 몇개 칸으로 구성되어 있는지 찾기
    CountGroupnum(num);
    // 3. 인접한 그룹쌍 찾기
    FindGroupPair();
    // 4. 각 그룹쌍 마다 조화로움 계산하기
    int InitScore = 0; 
    set<pair<int,int>>::iterator it;
    for(it = group_pair.begin(); it != group_pair.end(); it++){
        int x = it->first;
        int y = it->second;
        int tmp = CalScore(x,y);
        InitScore += tmp;
    }
    return InitScore;
}

void PrintGroupPair(){
    set<pair<int,int>>::iterator it;
    for(it = group_pair.begin(); it != group_pair.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}
void PrintGroupBoard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << group_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void PrintGroupNum(){
    for(int i=1; i<=29 ; i++)
        cout << groups_num[i] << " ";
    cout << endl;
}

void PrintGroupVal(){
    for(int i=1; i<=29 ; i++)
        cout << groups_val[i] << " ";
    cout << endl;
}

void Rotate_Center(){
    int tmp[n];
    int half = n/2;
    for(int j=half+1; j<n; j++){
        tmp[j] = board[half][j];
    }
    // 4번째 자리에 3번째 복분
    for(int j = half+1; j < n; j++){
        board[half][j] = board[j][half];
    }
    // 3번째 자리에 2번째 복붙
    for(int i = 1; i <= half; i++){
        board[half+i][half] = board[half][half-i];
    }
    // 2번째 자리에 1번째 복붙
    for(int j = 0; j < half; j++){
        board[half][j] = board[j][half];
    }
    // 1번째에 4번째 복붙
    for(int i=1; i<=half ; i++){
        board[half-i][half] = tmp[half+i];
    }
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
void Rotate_etc(){
    int half = n/2;
    int tmp_board[n][n];

    // 1영역 회전
    for(int i=0; i<half ; i++){
        for(int j=0; j<half; j++){
            tmp_board[j][half-i-1] = board[i][j];
        }
    }
    // 2영역 회전
    for(int i=half+1; i<n ; i++){
        for(int j=0; j<half; j++){
            tmp_board[j+half+1][n-i-1] = board[i][j];
        }
    }
    // 3영역 회전
    for(int i=0; i<half; i++){
        for(int j=half+1; j<n; j++){
            tmp_board[j-half-1][n-i-1] = board[i][j];
        }
    }
    // 4영역 회전
    for(int i=half+1; i<n; i++){
        for(int j=half+1; j<n; j++){
            tmp_board[j][n-i+half] = board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == half || j == half)
                continue;
            board[i][j] = tmp_board[i][j];
        }
    }
}
void Rotate(){
    // ㄱ. 가운데 십자가 반시계 방향으로 90도 회전
    Rotate_Center();
    // ㄴ. 나머지 정사각형은 각각 시계 방향으로 90도 회전 
    if(n == 3)
        return;
    Rotate_etc();
}
int GetScore(){
    // 1. 그룹화하기 
    int num = Grouping();
    // 2. 각 그룹에 몇개 칸으로 구성되어 있는지 찾기
    CountGroupnum(num);
    // 3. 인접한 그룹쌍 찾기
    FindGroupPair();
    // 4. 각 그룹쌍 마다 조화로움 계산하기
    int score = 0; 
    set<pair<int,int>>::iterator it;
    for(it = group_pair.begin(); it != group_pair.end(); it++){
        int x = it->first;
        int y = it->second;
        int tmp = CalScore(x,y);
        score += tmp;
    }
    return score;
}
int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    int ans = 0;
    // 1. 초기 예술 점수 얻기
    ans += GetInitScore();
    for(int i=0; i<3; i++){
        // 각 회전이후 점수 얻기 
        // 1. 회전하기 
        Rotate();
        ans += GetScore();
    }
    cout << ans;
    //PrintGroupBoard();
    //PrintGroupNum();
    //PrintGroupPair();
    //PrintGroupVal();
    return 0;
}