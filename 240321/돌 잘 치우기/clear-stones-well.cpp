#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define MAX_N 100


using namespace std;

int n,m,k;
int arr[MAX_N][MAX_N];
int tmp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool visited_stone[MAX_N][MAX_N];
vector<pair<int,int>> start_point;
vector<pair<int,int>> stone_pos;
vector<pair<int,int>> selected_stone_pos;
int stone_num;
queue<pair<int,int>> bfs_q;
int ans;

bool InRange(int x, int y){
    return x >=0 && x < n &&  y >= 0 && y < n;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(tmp[x][y] == 1 || visited[x][y] == true)
        return false;
    return true;
}

void BFS(){
    while(!bfs_q.empty()){
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        pair<int,int> pos = bfs_q.front();
        bfs_q.pop();
        int x= pos.first , y = pos.second;

        for(int i=0; i<4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny] = true;
                bfs_q.push(make_pair(nx,ny));
            }
        }
    }

}

int Count(){
    int cnt =0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j])
                cnt++;
    return cnt;
}

void Simulation(){
    for(int i=0; i<k; i++){
        pair<int,int> pos = start_point[i];
        int x,y;
        tie(x,y) = pos;
        bfs_q.push(make_pair(x,y));
        BFS();
        ans = max(ans,Count());
    }
}

void DeleteStone(){
    for(int i=0; i<(int) selected_stone_pos.size(); i++){
        pair<int,int> pos = selected_stone_pos[i];
        int x, y;
        tie(x,y) = pos;
        tmp[x][y] = 0;
        //cout << x << " " << y << endl;
    }
}

void InitializedVisited(){
    for(int i=0 ; i<n;i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}
void InitializedVisitedStone(){
    for(int i=0 ; i<n;i++)
        for(int j=0; j<n; j++)
            visited_stone[i][j] = false;
}

void InitializedTmp(){
    for(int i=0 ; i<n;i++)
        for(int j=0; j<n; j++)
            tmp[i][j] = arr[i][j];
}

void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << !visited[i][j] << " ";
        }
        cout << endl;
    }
}
void Output_tmp(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
}
void Choose(int num){

    if(num == m){
        //cout << "stone_size : " << selected_stone_pos.size() << endl;
        InitializedTmp();
        InitializedVisited();
        //InitializedVisitedStone();
        DeleteStone();
        //Output_tmp();
        Simulation();
        //Output();
        //cout << endl;
        return;
    }

    for(int i=0; i<stone_num; i++){
        pair<int,int> pos = stone_pos[i];
        int x,y;
        tie(x,y) = pos;
        if(visited_stone[x][y] == false){
            visited_stone[x][y] = true;
            selected_stone_pos.push_back(stone_pos[i]);
            Choose(num +1 );
            selected_stone_pos.pop_back();
            visited_stone[x][y] = false;
        }
    }
}

int main() {

    cin >> n >> k >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                stone_pos.push_back(make_pair(i,j));
                stone_num++;
            }
        }
            
    
    int r,c;
    for(int i=0 ;i<k; i++){
        cin >> r >> c;
        r--; c--; 
        start_point.push_back(make_pair(r,c));
    }

    Choose(0);

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}