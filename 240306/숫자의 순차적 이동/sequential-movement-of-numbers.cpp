#include <iostream>

using namespace std;

int n,m;
int arr[20][20];

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

bool InRange(int x, int y){
    return x>=0 && x <n && y>=0 && y<n;
}
pair<int,int> FindMaxPos(int x, int y){
    int max_num = 0;
    pair<int,int> max_pos;
    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(InRange(nx,ny) && arr[nx][ny] > max_num){
            max_num = arr[nx][ny];
            max_pos = make_pair(nx,ny);
        }
    }
    return max_pos;
}

void Move(int idx){
    pair<int,int> tmp_pos;
    int tmp_val = 0;
    int x; int y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == idx){
                tmp_pos = FindMaxPos(i,j);
                x = tmp_pos.first; y = tmp_pos.second;
                tmp_val = arr[x][y];
                arr[x][y] = arr[i][j];
                arr[i][j] = tmp_val;
                return; 
            }
        }
    }
}


void Simulate(){
    while(m--){
        for(int i=1; i<=n*n; i++){
            Move(i);
        }
    }
}

void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {

    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    Simulate();

    Output();

    return 0;
}