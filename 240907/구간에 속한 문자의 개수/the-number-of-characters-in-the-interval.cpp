#include <iostream>
#include <string>
using namespace std;

#define MAX_N 1002

int n,m,k;
int arr[MAX_N][MAX_N];
int sum_a[MAX_N][MAX_N];
int sum_b[MAX_N][MAX_N];
int sum_c[MAX_N][MAX_N];


void init(){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j] == 1){
                sum_a[i][j] = sum_a[i-1][j] + sum_a[i][j-1] - sum_a[i-1][j-1] + 1;
                sum_b[i][j] = sum_b[i-1][j] + sum_b[i][j-1] - sum_b[i-1][j-1];
                sum_c[i][j] = sum_c[i-1][j] + sum_c[i][j-1] - sum_c[i-1][j-1];
            }
            else if(arr[i][j] == 2){
                sum_a[i][j] = sum_a[i-1][j] + sum_a[i][j-1] - sum_a[i-1][j-1];
                sum_b[i][j] = sum_b[i-1][j] + sum_b[i][j-1] - sum_b[i-1][j-1] + 1;
                sum_c[i][j] = sum_c[i-1][j] + sum_c[i][j-1] - sum_c[i-1][j-1];
            }
            else if(arr[i][j] == 3){
                sum_a[i][j] = sum_a[i-1][j] + sum_a[i][j-1] - sum_a[i-1][j-1];
                sum_b[i][j] = sum_b[i-1][j] + sum_b[i][j-1] - sum_b[i-1][j-1];
                sum_c[i][j] = sum_c[i-1][j] + sum_c[i][j-1] - sum_c[i-1][j-1] + 1;
            }
        }
    }
}
void Print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << sum_a[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        string str;
        cin >> str;

        for(int j=0; j<m; j++){
            if(str[j] == 'a'){
                arr[i][j+1] = 1;
            }
            else if(str[j] == 'b'){
                arr[i][j+1] = 2;
            }
            else if(str[j] == 'c'){
                arr[i][j+1] = 3;
            }
        }
    }



    int r1, c1, r2, c2;
    init();
    //Print();

    for(int i=0; i<k; i++){
        cin >> r1 >> c1 >> r2 >> c2;

        int ans_a, ans_b, ans_c;
        ans_a = sum_a[r2][c2] - sum_a[r1-1][c2] - sum_a[r2][c1-1] + sum_a[r1-1][c1-1];
        ans_b = sum_b[r2][c2] - sum_b[r1-1][c2] - sum_b[r2][c1-1] + sum_b[r1-1][c1-1];
        ans_c = sum_c[r2][c2] - sum_c[r1-1][c2] - sum_c[r2][c1-1] + sum_c[r1-1][c1-1];

        cout << ans_a << " " << ans_b <<" " << ans_c << endl;
    }

    return 0;
}