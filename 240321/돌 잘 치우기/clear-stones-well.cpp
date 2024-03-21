#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

int n,k,m;
int a[MAX_N][MAX_N];

int ans;

vector<pair<int,int>> s_pos;
vector<pair<int,int>> stone_pos;
vector<pair<int,int>> selected_stones;


queue<pair<int,int>> q;
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}
bool CanGo(int x, int y){
    return InRange(x,y) && ! a[x][y] && !visited[x][y];
}

void BFS(){
    while(!q.empty()){

        pair<int,int> curr_pos = q.front();
        int x = curr_pos.first, y= curr_pos.second;
        q.pop();

        int dx[DIR_NUM] ={1,-1,0,0};
        int dy[DIR_NUM] = {0,0,1,-1};

        for(int dir =0; dir <DIR_NUM; dir++){
            int nx = x +dx[dir] , ny = y+dy[dir];
            if(CanGo(nx,ny)){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int Calc(){
    for(int i=0 ; i<m; i++) {
        int x = selected_stones[i].first, y= selected_stones[i].second;
        a[x][y] = 0;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] =0;

    for(int i=0; i <k; i++) {
        q.push(s_pos[i]);
        visited[s_pos[i].first][s_pos[i].second] = true;
    }

    BFS();

    for(int i=0; i<m; i++){
        int x = selected_stones[i].first , y = selected_stones[i].second;
        a[x][y] = 1;
    }

    int cnt = 0;
    for(int i=0; i<n ; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j])
                cnt++;
    
    return cnt;
}

void FindMax(int idx, int cnt){
    if(idx == (int) stone_pos.size()){
        if(cnt == m)
            ans = max(ans, Calc());
        return;
    }

    selected_stones.push_back(stone_pos[idx]);
    FindMax(idx+1, cnt+1);
    selected_stones.pop_back();

    FindMax(idx+1, cnt);
}

int main(){

    cin >> n >> k >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1)
                stone_pos.push_back(make_pair(i,j));
        }
    
    for(int i=0;i<k;i++){
        int r,c;
        cin >> r >> c ;
        r--; c--;
        s_pos.push_back(make_pair(r,c));
    }
    FindMax(0,0);

    cout << ans;
    return 0;
}