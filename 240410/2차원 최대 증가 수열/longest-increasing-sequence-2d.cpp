#include <iostream>
#include <climits>

#define MAX_NM 50

using namespace std;

int n,m;
int arr[MAX_NM][MAX_NM];
int dp[MAX_NM][MAX_NM];

void Initialize(){
    for(int i=0; i<n; i++)
        for(int j=0;j<m; j++)
            dp[i][j] = INT_MIN;

    dp[0][0] = 1;
}
void Jump (int x, int y){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(arr[x][y] > arr[i][j])
                dp[x][y] = max(dp[x][y], dp[i][j] + 1);
        }
    }
}

void Output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    
    Initialize();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Jump(i,j);
            //Output();
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}