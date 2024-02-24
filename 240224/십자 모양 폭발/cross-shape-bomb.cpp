#include <iostream>
#include <climits>

using namespace std;

int n;
int r,c;
int arr[200][200];

bool InRange( int x, int y){
    return x>=0 && x < n && y >=0 && y < n;
}

void Bomb (int x, int y){
    int step = arr[x][y];
    //cout << "step : " << step << endl;
    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};
    for(int i=0; i<4; i++){
        for(int j=0; j<step; j++){
            int nx = x+dx[i]*(j);
            int ny = y+dy[i]*(j);
            if(InRange(nx,ny)){
                //cout << nx << " " << ny << endl;
                arr[ nx][ny] = 0;
            }
        }
    }
}
int Check(int col){
    int max_row = -1;
    for(int row = 0; row <n; row++)
        if(arr[row][col] == 0)
            max_row = max(max_row,row);
    return max_row;
}

void Fall(){

    for(int col=0; col < n; col++){
        if(Check(col)!= -1){
            int row = Check(col);
            //cout << row << " ";
            int temp_row = row;
            for(int i=row-1; i>=0; i--){
                if(arr[i][col]!=0){
                    arr[temp_row++][col] =arr[i][col];
                    arr[i][col]=0; 
                }
            }
        }
    }
    
}

int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
        
    
    cin >> r>> c; r--; c--;

    Bomb(r,c);
    Fall();

    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cout  << arr[i][j] << " ";
        }
        cout << endl;
    }
        


    // 여기에 코드를 작성해주세요.
    return 0;
}