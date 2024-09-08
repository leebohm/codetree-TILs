#include <iostream>

#define MAX_N 401

using namespace std;

int n,k;
int board[MAX_N][MAX_N];
int s[MAX_N][MAX_N];
int ans = 0;

int main(){
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> board[i][j];
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            s[i][j] = s[i][j-1] + board[i][j];
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            int sum_all = 0;

            for(int r = i-k; r<=i+k; r++){
                int c = k - abs(i-r);

                if(1 <= r && r<=n)
                    sum_all += s[r][min(j+c,n)]- s[r][max(j-c-1,0)];
            }

            ans = max(ans, sum_all);
        }
    cout << ans;
}