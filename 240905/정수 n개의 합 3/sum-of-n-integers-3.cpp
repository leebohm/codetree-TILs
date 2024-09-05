#include <iostream>

using namespace std;

#define MAX_N 502

int n,k;
int arr[MAX_N][MAX_N];
int pre_sum[MAX_N][MAX_N];

void print_pre_sum(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n ;j++){
            cout << pre_sum[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] - pre_sum[i-1][j-1] + arr[i][j];
        }
    }

    int ans = 0;
    for(int i=k; i<=n; i++){
        for(int j=k; j<=n; j++){
            ans = max(ans, (pre_sum[i][j] - pre_sum[i-k][j]-
                            pre_sum[i][j-k] + pre_sum[i-k][j-k]));

        }
    }
    //print_pre_sum();
    cout << ans;
    return 0;
}