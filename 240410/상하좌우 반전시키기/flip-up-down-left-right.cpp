#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N][MAX_N];
int ans;

int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};

bool InRange(int x, int y){
    return  x >= 0 && x < n && y >=0 && y < n;
}

void Change(int x, int y){
    for(int i=0; i<5; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(InRange(nx,ny)){
            if(arr[nx][ny] == 0)
                arr[nx][ny] = 1;
            else
                arr[nx][ny] = 0;
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
    cout << endl;
}

int main() {

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                cin >> arr[i][j];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i-1][j] == 0){
                Change(i, j);
                ans++;
            }
            //Output();   
        }
    }   

    bool flag = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0)
                flag = false;
        }
    }
    
    if(flag == true)
        cout << ans;
    else
        cout << -1;

    // 여기에 코드를 작성해주세요.
    return 0;
}