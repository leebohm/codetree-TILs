#include <iostream>

using namespace std;

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int n;
int m;

int arr[20][20];

bool InRange(int x, int y){
    return x>=0 && x <n && y>=0 && y <n;
}

void Move(int cnt, int x, int y){

    int tmp = 0;
    int idx = -1;
    int tmp_value = 0;

    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(InRange(nx,ny)){
            tmp = max(arr[nx][ny], tmp);
            if(tmp == arr[nx][ny]){
                idx = i;
            }
        }

    }

    if(idx != -1){
        tmp_value = arr[x][y];
        int nx = x+dx[idx];
        int ny = y+dy[idx];
        arr[x][y] = arr[nx][ny];
        arr[nx][ny] = tmp_value;
    }

    return;
}

void  Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    

    for(int i=0; i<m; i++){
        int cnt = n*n;
        int key =1;
        for(int k=0; k<n*n; k++){
            for(int a=0; a<n; a++){
                for(int b=0; b<n; b++){
                    if(key > n*n) break;
                    if(key == arr[a][b]){
                        Move(key, a, b);
                        //Output();
                        key++;
                    }
                        
                }
                
        } 

        }
          
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}