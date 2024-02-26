#include <iostream>

using namespace std;

int n,m,k;

int arr[100][100];
int temp[100][100];

void Rotate(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = arr[n-j+1][i];
    
    for(int i=0; i<n;i++)
        for(int j=0;j<n; j++)
            arr[i][j] = temp[i][j];
}

int GetEndRow(int start_row, int col){
    int key = arr[start_row][col];
    int end_row = start_row+1;
    for(int i=start_row+1; i<n; i++){
        if(key == arr[i][col]) end_row++; 
        else break;
    }
    return end_row-1;
}

void Bomb(){
    for(int j=0; j<n;j++){
        for(int i=0; i<n; i++){
            int end_row = GetEndRow(i,j);
            if(end_row-i+1 >=m){
                //cout << end_row-i+1 <<" " << m <<" " << i << " " <<j <<" "<< end_row  << endl;
                for(int k= i; k<=end_row;k++)
                    arr[k][j] = 0;
            }
        }
    }
}

void Fall(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = 0;
    
    for(int j=0; j<n; j++){
        int temp_row = n-1;
        for(int i=n-1;i>=0; i--){
            if(arr[i][j] != 0)
                temp[temp_row--][j] = arr[i][j];
        }
    }

    for(int i=0; i<n;i++)
        for(int j=0;j<n; j++)
            arr[i][j] = temp[i][j];

}

void Output(){
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];


    for(int i=0; i<k; i++){
        Bomb();
        Fall();
        if(n!=1)
            Rotate();
        Fall();
    }
    
    int ans =0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]!=0) ans++;
        }
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}