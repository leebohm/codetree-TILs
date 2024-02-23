#include <iostream>

using namespace std;

int n,m,q;

int arr[100][100];
int spare[100][100];
int r1[100];
int c1[100];
int r2[100];
int c2[100];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

bool InRange(int x , int y){
    return x >= 0 && x <n && y>=0 && y < m;
}

int ComputeAverage(int x, int y){
    int val = 0;
    val += spare[x][y];
    int cnt = 1;
    for(int i=0; i<4 ; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(InRange(nx,ny)){
            val += spare[nx][ny];
            cnt++;
        }   
    }
    return val / cnt;
}

void Move(int r1, int c1, int r2, int c2){

    int temp1 = arr[r1][c1];
    int temp2 = arr[r1][c2];
    int temp3 = arr[r2][c2];
    int temp4 = arr[r2][c1];

    for(int i = c2-1; i >= c1; i--){
        arr[r1][i+1] = arr[r1][i];
    }

    for(int i=r2-1; i>= r1+1; i--){
        arr[i+1][c2] = arr[i][c2];
    }
    arr[r1+1][c2] = temp2;
    
    for(int i=c1; i< c2-1; i++){
        arr[r2][i] = arr[r2][i+1];
    }
    arr[r2][c2-1] = temp3;
    
    for(int i = r1; i < r2-1; i++){
        arr[i][c1] = arr[i+1][c1];
    }
    arr[r2-1][c1] = temp4;
}

void CopyArr(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            spare[i][j] = arr[i][j];
}

int main() {
    cin >> n >> m >> q;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    
    for(int i=0; i<q; i++){
        int a,b,c,d;
        cin >> a >> b>> c>> d;
        r1[i] = a-1; c1[i] = b-1;
        r2[i] = c-1; c2[i] = d-1;
    }

    for(int i=0; i<q; i++){
        Move(r1[i],c1[i],r2[i],c2[i]);
        CopyArr();
        for(int x = r1[i]; x <= r2[i]; x++){
            for(int y = c1[i]; y<= c2[i]; y++){
               arr[x][y] = ComputeAverage(x,y); 
            }
        }
    }
    

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}