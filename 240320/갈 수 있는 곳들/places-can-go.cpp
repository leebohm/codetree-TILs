#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 100

using namespace std;

int n;
int k;
int arr[MAX_N][MAX_N];
vector<pair<int,int>> start_pos;
queue<pair<int,int>> q;
int ans;
bool visited[MAX_N][MAX_N];
int visited_num[MAX_N][MAX_N];

void InitializeVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}

bool InRange(int x, int y){
    return x>=0 && x <n && y >= 0 && y<n;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(arr[x][y] != 0 || visited[x][y] == true)
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        pair<int,int> pos = q.front();
        int x = pos.first;
        int y = pos.second;
        //cout <<"BFS : "<<  x << " " << y  << "q size : " << (int) q.size() << endl;
        q.pop();
        //cout <<"BFS : "<<  x << " " << y  << "q size : " << (int) q.size() << endl;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(CanGo(nx,ny)){
                visited[nx][ny]= true;
                visited_num[nx][ny]++;
                q.push(make_pair(nx,ny));

            }
        }
    }
}

void Count(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited_num[i][j] > 0)
                ans++;
        }
    }
}


int main() {

    int r, c;

    cin >> n >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<k; i++){
        cin >> r >> c;
        r--; c--;
        start_pos.push_back(make_pair(r,c));
    }

    for(int i=0; i<(int) start_pos.size(); i++){

        //cout << " i : " << i << endl;
        InitializeVisited();
        pair<int,int> pos = start_pos[i];
        int x, y;
        x = pos.first;
        y = pos.second;
        visited[x][y] = true;
        visited_num[x][y]++;
        q.push(make_pair(x,y));
        BFS();

    }
    Count();
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}