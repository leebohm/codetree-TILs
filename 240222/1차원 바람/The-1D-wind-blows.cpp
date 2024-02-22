#include <iostream>

using namespace std;

int n,m,q;
int arr[100][100];
int row_num[100];
bool dir[100];


void Move(int row, int d){
    if(d == true){
        int temp = arr[row][m-1];
        for(int i=m-2; i>=0 ; i--){
            arr[row][i+1] = arr[row][i];
        }
        arr[row][0]= temp;

    }
    else{
        int temp = arr[row][0];
        for(int i=0; i<m-1; i++){
            arr[row][i] = arr[row][i+1];
        }
        arr[row][m-1] = temp;

    }

}

bool Check (int key_row, int check_row){
    for(int i = 0; i<m; i++){
        if(arr[key_row][i]==arr[check_row][i]) return true;
    }
    return false;
}

int main() {

    cin >> n >> m >> q;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }

    for(int i=0; i<q; i++){
        int x; char y;
        cin >> x >>  y ;
        row_num[i] = x-1;
        if(y=='L') dir[i] = true;
        else dir[i] = false;
    }
    
    for(int i=0; i< q; i++){
        int key_row = row_num[i];
        bool d = dir[i];
        Move(key_row,d);
        int check_row1 = key_row -1;
        int check_row2 = key_row +1;


        while(check_row1 >=0){
            if(Check(key_row, check_row1)){
                d = !d;
                Move(check_row1,d);
                key_row = check_row1;
                check_row1--;
            }
            else break;
        }
        key_row = row_num[i];
        d = dir[i];
        while(check_row2<n){
            if(Check(key_row, check_row2)){
                d = !d;
                Move(check_row2,d);
                key_row = check_row2;
                check_row2++;
            }
            else break;

        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}