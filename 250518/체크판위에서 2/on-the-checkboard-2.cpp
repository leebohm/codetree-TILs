#include <iostream>

using namespace std;

#define MAX_N 20

int r,c;
int board[MAX_N][MAX_N];

int main(){

    cin >> r >> c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char ch;
            cin >> ch;
            if(ch == 'W')
                board[i][j] = 0;
            if(ch == 'B')
                board[i][j] = 1;
        }
    }

    int x = 0;
    int y = 0;
    int cnt = 0;
    for(int a1=x+1; a1<r-1; a1++){
        for(int b1=y+1; b1<c-1; b1++){
            for(int a2=a1 + 1; a2 < r-1; a2++){
                for(int b2=b1+1; b2 < c-1; b2++){
                    if(board[x][y] != board[a1][b1] && board[a1][b1] != board[a2][b2] && board[a2][b2] != board[r-1][c-1])
                        cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}