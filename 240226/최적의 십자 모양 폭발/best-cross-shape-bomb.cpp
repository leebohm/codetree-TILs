#include <iostream>

int n;
int arr[50][50];
int temp[50][50];
int origin_arr[50][50];
using namespace std;

bool InBombRange(int x, int y, int center_x, int center_y, int bomb_range){
    return (x==center_x || y==center_y)&& abs(x-center_x) + abs(y-center_y)<bomb_range;
}

void Bomb(int center_x, int center_y){
    int bomb_range = arr[center_x][center_y];
    arr[center_x][center_y] =0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(InBombRange(i,j,center_x,center_y,bomb_range))
                arr[i][j] = 0; 
        }

}
void Output(){
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Output_temp(){
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Fall(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] =0;

    

    for(int j=0; j<n; j++){
        int temp_row= n-1;
        for(int i=n-1; i>=0; i--){
            if(arr[i][j]!=0)
                temp[temp_row--][j] = arr[i][j];
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            arr[i][j]= temp[i][j];
}

int Count(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if((arr[i][j] == arr[i][j+1])&& arr[i][j]!=0) cnt++;
        }
    }
    for(int j=0; j<n; j++){
        for(int i=0; i<n-1; i++){
            if((arr[i][j]== arr[i+1][j])&& arr[i][j]!=0) cnt++;
        }
    }
    return cnt;
}

void Reset(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            arr[i][j] = origin_arr[i][j];
}

int main() {
    
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> origin_arr[i][j];
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Reset();
            Bomb(i,j);
            Fall();
            int tmp = Count();
            ans = max(ans, tmp);
        }
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}