#include <iostream>

using namespace std;

int n,m,r,c,m1,m2,m3,m4,dir;
int arr[100][100];

void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << arr[i][j] << " ";
        
        cout << endl;
    }
}

void Move_clockwise(int x, int y){
    int temp1 = arr[x][y];
    int temp2 = arr[x-m1][y-m1];
    int temp3 = arr[x-m1-m2][y-m1+m2];
    int temp4 = arr[x-m4][y+m4];

    int i = x-m1; int j = y-m1;
    for(int k = 0; k <m1; k++){
        arr[i][j] = arr[i-1][j-1];
        i++; j++;
    }
    
    i = x-m1-m2; j= y-m1+m2;
    for(int k=0; k < m2; k++){
        arr[i][j] = arr[i+1][j-1];
        i++;j--;
    }
    arr[x-m1-1][y-m1+1] = temp2;


    i = x-m1-m2+m3; j = y-m1+m2+m3;
    for(int k=0; k<m3;k++){
        arr[i][j] = arr[i-1][j-1];
        i--; j--;
    }
    arr[x-m1-m2+1][y-m1+m2+1] = temp3; 

    i = x; j = y;
    for(int k=0; k< m4; k++){
        arr[i][j] = arr[i-1][j+1];
        i--;j++;
    }
    arr[x-m4+1][y+m4-1] = temp3;

}

void Move_counterclockwise(int x, int y){
    int temp1 = arr[x][y];
    int temp2 = arr[x-m1][y+m1];
    int temp3 = arr[x-m1-m2][y+m1-m2];
    int temp4 = arr[x-m4][y-m4];

    int i=x-m1; int j= y+m1;
    for(int k=0; k< m1; k++){
        arr[i][j] = arr[i+1][j-1];
        i++;j--;
    }

    i = x-m1-m2; j = y+m1-m2;
    for(int k=0; k<m2; k++){
        arr[i][j] = arr[i+1][j+1];
        i++;j++;
    }
    arr[x-m1-1][y+m1-1] = temp2;

    i = x-m4; j = y-m4;
    for(int k=0; k<m3; k++){
        arr[i][j] = arr[i-1][j+1];
        i--; j++;
    }
    arr[x-m1-m2+1][y+m1-m2-1] = temp3;

    i=x; j=y;
    for(int k= 0;k < m4; k++) {
        arr[i][j] = arr[i-1][j-1];
        i--;j--;
    }
    arr[x-m4+1][y-m4+1] = temp4;

}


int main() {

    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    if(dir == 0)
        Move_counterclockwise(r-1,c-1);
    else
        Move_clockwise(r-1,c-1);
    
    Output(); 
    // 여기에 코드를 작성해주세요.
    return 0;
}