#include <iostream>
#include <climits>

#define MAX_N 300

using namespace std;

int n;
int arr[MAX_N+1][MAX_N+1];
int prefix_sum[MAX_N+1][MAX_N+1];
int dp[MAX_N+1];

int GetSum(int x1, int y1, int x2, int y2){
    return prefix_sum[x2][y2] - prefix_sum[x1-1][y2] -
            prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
}

int GetMaxArea(int x1, int x2){

    for(int y=1; y<=n; y++){
        int value = GetSum(x1, y, x2, y);
        dp[y] = max(value, dp[y-1] + value);
    }

    int max_area = INT_MIN;
    for(int y=1; y<=n; y++)
        max_area = max(max_area, dp[y]);
    
    return max_area;
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];
    
    prefix_sum[0][0] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            prefix_sum[i][j] = prefix_sum[i-1][j] +
                                prefix_sum[i][j-1] - 
                                prefix_sum[i-1][j-1] +
                                arr[i][j];
                    
    int ans = INT_MIN;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n;j++)
            ans = max(ans, GetMaxArea(i,j));
    
    cout << ans;

    return 0;
}