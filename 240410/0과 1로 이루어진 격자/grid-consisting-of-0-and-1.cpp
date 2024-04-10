#include <iostream>
#include <string>
#define MAX_N 10
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int ans;
string str;

void Change(int x, int y){
    for(int i=0; i<=x; i++){
        for(int j=0; j<=y; j++){
            arr[i][j] = 1 - arr[i][j];
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
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }
       
    
    for(int i=1;i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i-1][j] == 1){
                Change(i,j);
                ans++;
            }
            Output();
        }
    }
    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}