#include <iostream>
#include <climits>

#define MAX_N 1000
using namespace std;

int n;
int arr[MAX_N];
int dp[MAX_N];

void Initialize(){
    for(int i=0; i<=n; i++)
        dp[i] = 1;
    
    dp[0] = 0;
}
void Output(){
    for(int i=0; i<=n; i++)
        cout << dp[i] << " ";
    cout << endl;
}
int main() {
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    Initialize();

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]> arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        //Output();
    }

    int ans = 0;
    for(int i=0; i<=n; i++)
        ans = max(ans, dp[i]);
    
    cout << ans;

    return 0;
}