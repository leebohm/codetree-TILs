#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 25
using namespace std;

int n;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> neighbor;
int people_num;

bool InRange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y <n;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(visited[x][y] == true || arr[x][y] == 0)
        return false;
    return true;
}

void DFS(int x,int y){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(CanGo(nx,ny)){
            visited[nx][ny] = true;
            people_num++;
            DFS(nx,ny);
        }
    }
}
int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    int neighbor_cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(CanGo(i,j)){
                neighbor_cnt++;
                people_num = 1;
                visited[i][j] = true;
                DFS(i,j);
                neighbor.push_back(people_num);
            }
                
        }  
    }
    cout << neighbor_cnt << endl;
    sort(neighbor.begin(),neighbor.end());
    
    for(int i=0; i<(int) neighbor.size(); i++){
        cout << neighbor[i] << endl;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}