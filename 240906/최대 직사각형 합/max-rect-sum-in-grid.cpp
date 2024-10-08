#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 302

int arr[MAX_N][MAX_N];
int n;
int pre_sum[MAX_N][MAX_N];

void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] - pre_sum[i-1][j-1] + arr[i][j];
        }
    }
} 

void Print(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << pre_sum[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    init();

    //Print();

    int ans = -INT_MAX;

    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=i; k++){
                for(int l=1; l<=j; l++){
                    int tmp = pre_sum[i][j] - pre_sum[i-k][j] - pre_sum[i][j-l] + pre_sum[i-k][j-l];
                    //cout << tmp << " ";
                    ans = max(ans, tmp);
                }
                
            }
            
        }
    }

    cout << ans;
    return 0;
}