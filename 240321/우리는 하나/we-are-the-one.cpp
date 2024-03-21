#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

#define MAX_N 8

using namespace std;

int n,k,u,d;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int,int>> city; 
vector<pair<int,int>> selected_city; 
queue<pair<int,int>> q;
int ans;

bool InRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y, int target_num){
    if(InRange(x,y) == false)
        return false;
    
    int tmp = abs(target_num - arr[x][y]);
    if( !(tmp >= u && tmp <= d) || visited[x][y])
        return false;
    return true;
}

void BFS(){
    while(!q.empty()){
        pair<int,int> pos = q.front();
        int x,y;
        x = pos.first; y = pos.second;
        q.pop();
        int target_num = arr[x][y];

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (CanGo(nx,ny,target_num)){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int CountCity(){
    int num = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j])
                num++;
    return num;
}

void InitializedVisited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}

void Choose(int idx, int cnt){

    if(cnt == k){
        //cout << (int) selected_city.size() << endl;
        InitializedVisited();
        for(int i=0; i < (int) selected_city.size(); i++){
            pair<int,int> pos = selected_city[i];
            int x,y;
            tie(x,y) = pos;
            q.push(make_pair(x,y));
            visited[x][y] = true;
        }
        BFS();
        ans = max(ans, CountCity());
        return;
    }

    if(idx == (int) city.size())
        return;

    pair<int,int> pos = city[idx];
    int x,y;
    tie(x,y) = pos;
    selected_city.push_back(make_pair(x,y));
    Choose(idx+1,cnt+1);
    selected_city.pop_back();

    Choose(idx+1, cnt);

}

int main() {

    cin >>  n >> k >> u >> d;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            city.push_back(make_pair(i,j));
        }

    Choose(0,0);

    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}