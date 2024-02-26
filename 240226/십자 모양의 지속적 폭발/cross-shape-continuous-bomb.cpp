#include <iostream>

using namespace std;

int n,m;
int arr[200][200];
int temp[200][200];
int cols[10];

bool BombRange(int x,int y, int center_x, int center_y , int bomb_range){
    return  (center_x == x || center_y == y) && (abs(x-center_x)+abs(y-center_y)) <bomb_range;
}

void Bomb(int center_x, int center_y){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(center_x==i && center_y==j) continue;
            if(BombRange(i,j,center_x,center_y,arr[center_x][center_y])){
                arr[i][j] = 0;
            }
        }
    arr[center_x][center_y]= 0;
}

void Fall(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            temp[i][j] = 0; 
        }
    
    for(int j=0; j<n; j++){
        int temp_row = n-1;
        for(int i=n-1; i>=0; i--){
            if(arr[i][j]!=0)
                temp[temp_row--][j] = arr[i][j];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            arr[i][j] = temp[i][j];
        
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<m; i++){
        int c;
        cin >> c;
        cols[i] = c-1;
    }
        

    for(int i=0; i<m;i++){
        int idx = cols[i];

        for(int row=0; row<n; row++){
            if(arr[row][idx]!= 0){
                Bomb(row,idx);
                Fall();
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
        
    // 여기에 코드를 작성해주세요.
    return 0;
}