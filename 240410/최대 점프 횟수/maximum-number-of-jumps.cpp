#include <iostream>

#define MAX_N 1001
using namespace std;

int n;
int arr[MAX_N];
int dp[MAX_N];

void Output(){
    for(int i=0; i<n; i++)
        cout << dp[i] << " ";
    cout << endl;
}
int main(){
    
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        int tmp = arr[i];
        if(tmp != 0){
            for(int j=i+1; j<=i+tmp; j++){
                dp[j] = max(dp[i]+1, dp[j]);
            }
        }
        //Output();       
    }
    int ans = 0;

    for(int i=1; i<n; i++){
        ans = max(ans, dp[i]);
        if(dp[i] == 0)
            break;
    }

        
    
    cout << ans;

    return 0;
}