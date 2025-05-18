#include <iostream>

using namespace std;

#define MAX_N 25

int board[MAX_N][MAX_N];
int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for(int r = 0; r<n; r++){
        for(int c = 0; c<n; c++){
            int tmp = 0;
            for(int idx = c; idx < min(c+3,n); idx++){
                if(board[r][idx])
                    tmp++;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans;
    
    return 0;
}