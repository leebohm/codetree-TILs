#include <iostream>

#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int block_size = 0;
int max_block_size = 0;
int block_num = 0;

void Initialized_visited(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = false;
}

bool InRange(int x, int y){
    return x >= 0 && x <n && y >= 0 && y <n;
}

bool CanGo(int x, int y, int num){
    if(InRange(x,y) == false)
        return false;
    if(visited[x][y] == true || num != arr[x][y])
        return false;
    return true;
}

void DFS(int x, int y, int num){
    block_size++;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(CanGo(nx,ny, num)){
            visited[nx][ny]= true;
            DFS(nx,ny,num);
        }
    }
}

void Simulation(){
    block_num = 0; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //Initialized_visited();
            int num = arr[i][j];
            if(CanGo(i,j,num)){
                visited[i][j] = true;
                block_size = 0; 
                DFS(i,j,num);
                if(block_size >= 4){
                    block_num++;
                    //cout << i << " " << j  << endl;
                }
                    
                max_block_size = max(max_block_size, block_size);
            }
        }
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    Simulation();

    cout << block_num << " ";
    cout << max_block_size;
    // 여기에 코드를 작성해주세요.
    return 0;
}