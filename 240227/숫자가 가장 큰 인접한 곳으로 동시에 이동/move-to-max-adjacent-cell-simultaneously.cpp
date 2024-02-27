#include <iostream>

using namespace std;

int n,m,t;
int arr[20][20];
int temp[20][20];
int r[400];
int c[400];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool InRange(int x, int y){
    return x>=0 && x <n && y>=0 && y<n;
}

void Reset_temp(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            temp[i][j] == 0;
        }
}

void Move(int x, int y){
    int ans = 0; 
    int idx = 0;
    int idy = 0;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(InRange(nx,ny)){
            ans = max(arr[nx][ny],ans);
            if(ans == arr[nx][ny]){
                idx = nx; idy = ny;
            } 
        }
    }
    temp[idx][idy]++;
}

void GetBombsPose(){
    int x=0; int y=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(temp[i][j]==1){
                r[x++]=i;
                c[y++]=j;
            }
        }
    }
}

int CountBomb(){
    int ans =0; 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(temp[i][j] == 1) ans++;
    return ans;
}

int main() {

    cin >>  n >>  m >> t;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[n][m];
    
    int x; int y;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        r[i] = x; c[i] = y;
    }
    
    while(t--){
        Reset_temp();
            for(int i=0; i<m; i++){
                Move(r[i],c[i]);
            }
        GetBombsPose();
    }
    

    int ans = CountBomb();
    cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}